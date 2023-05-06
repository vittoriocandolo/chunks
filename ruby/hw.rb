#!/usr/bin/env ruby

require 'optparse'

# this script is specific for my hardware

# early execution of the only command
GPUS = {}
  `lshw -C display 2> /dev/null`.lines.each do |line|
    if line =~ /description: (.*)/
      name = $1.strip
      bus_id = `lshw -C display -businfo 2> /dev/null | tail -n 1`.lines[0].split[3].downcase
      clock_speed = `lshw -C display -numeric 2> /dev/null`.lines.grep(/clock/).first&.split(':')[1]&.strip
      GPUS[bus_id] = {
        name: name,
        clock_speed: clock_speed
      }
    end
  end

def cpu_info
  info = {}
  cpu_info_file = "/proc/cpuinfo"
  if File.exist?(cpu_info_file)
    cpu_info = File.read(cpu_info_file)
    cpu_info.lines.each do |line|
      key, value = line.split(":")
      info[key.strip] = value.strip if key && value
    end
  end
  info
end

def memory_info
  info = {}
  mem_info_file = "/proc/meminfo"
  if File.exist?(mem_info_file)
    mem_info = File.read(mem_info_file)
    mem_info.lines.each do |line|
      key, value = line.split(":")
      info[key.strip] = value.strip if key && value
    end
  end
  info
end

def disk_info
  disks = {}
  diskstats_file = "/proc/diskstats"
  if File.exist?(diskstats_file)
    diskstats = File.read(diskstats_file)
    diskstats.lines.each do |line|
      fields = line.split
      name = fields[2]
      next unless name.start_with?("sd", "hd", "nv", "vd") # ,"lo")
      reads_completed, reads_merged, sectors_read, time_spent_reading, writes_completed, writes_merged, sectors_written, time_spent_writing, io_in_progress, time_spent_doing_io = fields[3..12].map(&:to_i)
      disks[name] = {
        reads_completed: reads_completed,
        reads_merged: reads_merged,
        sectors_read: sectors_read,
        time_spent_reading: time_spent_reading,
        writes_completed: writes_completed,
        writes_merged: writes_merged,
        sectors_written: sectors_written,
        time_spent_writing: time_spent_writing,
        io_in_progress: io_in_progress,
        time_spent_doing_io: time_spent_doing_io
      }
    end
  end
  disks
end

def network_info
  networks = {}
  network_dir = "/sys/class/net"
  if Dir.exist?(network_dir)
    Dir.entries(network_dir).each do |entry|
      next if entry.start_with?(".")
      network_file = File.join(network_dir, entry, "address")
      if File.exist?(network_file)
        mac_address = File.read(network_file).strip
        networks[entry] = { mac_address: mac_address }
      end
    end
  end
  networks
end

# TODO may be improved for different hardware
def gpu_info
  GPUS
end

def temp
  max = Dir.glob('/sys/class/thermal/thermal_zone*/temp').map do |zone|
    File.read(zone).to_i / 1000.0
  end.max
  puts "max_temp: #{max}°"
end

options = {}

OptionParser.new do |opts|
  opts.banner = "Usage: hwinfo.rb [options]"

  opts.on("-c", "--cpu", "Display CPU info") do |c|
    options[:cpu] = c
  end

  opts.on("-m", "--memory", "Display memory info") do |m|
    options[:memory] = m
  end

  opts.on("-d", "--disk", "Display disk info") do |d|
    options[:disk] = d
  end

  opts.on("-n", "--network", "Display network info") do |n|
    options[:network] = n
  end

  opts.on("-g", "--gpu", "Display GPU info") do |g|
    options[:gpu] = g
  end

  opts.on("-t", "--temp", "Display current max temperature") do |t|
    options[:temp] = t
  end

  opts.on("-a", "--all", "Display all available hardware info") do |a|
    options[:all] = a
  end

  opts.on("-h", "--help", "Display help") do |h|
    options[:help] = h
  end
end.parse!

if options[:help] || options.empty?
  puts <<-HELP
Usage: hw.rb [options]
-c, --cpu Display CPU info
-m, --memory Display memory info
-d, --disk Display disk info
-n, --network Display network info
-g, --gpu Display GPU info
-t, --temp Display temperature info
-a, --all Display all available hardware info
-h, --help Display help
HELP
  exit
end

if options[:cpu] || options[:all]
  puts "CPU info:"
  cpu_info.each { |key, value| puts "#{key}: #{value}" }
  puts ""
end

if options[:memory] || options[:all]
  puts "Memory info:"
  memory_info.each { |key, value| puts "#{key}: #{value}" }
  puts ""
end

if options[:disk] || options[:all]
  puts "Disk info:"
  disk_info.each do |name, info|
    puts "#{name}:"
    info.each { |key, value| puts " #{key}: #{value}" }
  end
  puts ""
end

if options[:network] || options[:all]
  puts "Network info:"
  network_info.each do |name, info|
    puts "#{name}:"
    info.each { |key, value| puts " #{key}: #{value}" }
  end
  puts ""
end

if options[:gpu] || options[:all]
  puts "GPU info:"
  gpu_info.each do |name, info|
    puts "#{name}:"
    info.each { |key, value| puts " #{key}: #{value}" }
  end
  puts ""
end

if options[:temp] || options[:all]
  puts "Temperature info:"
  temp
  puts ""
end
