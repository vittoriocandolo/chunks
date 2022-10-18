# Stampare a video il numero di utenti con la home directory in /home

    cat /etc/passwd | cut -d':' -f6 | grep '^home' | wc -l

# Stampare a video il numero di comandi unici contenuti nella history

    cat ~/.bash_history | sort | uniq | wc -l

# Stampare ricorsivamente da pwd directory aaccessibili da ogni utente

    find . -type d -ls | grep 'r.xr.xr.x'


# Stampa linee uniche e le conta (tipo 2 abc \n 3 bbb) da file dato

    sort test.txt | uniq -c

# Estrarre UID (3o campo) da /etc/passwd e ordinarli

    cut -d: -f3 /etc/passwd | sort -n

# Estrarre UID da /etc/passwd

    cut -d: -f3 /etc/passwd

# Estrarre le ore da 'date'

    date | tr -s ' ' | cut -d' ' -f4 | cut -d: -f1

    # oppure

    date | cut -d' ' -f5 | cut -d: -f1

