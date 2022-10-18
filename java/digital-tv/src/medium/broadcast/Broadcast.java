package medium.broadcast;

import java.time.*;
import java.util.Iterator;
import java.util.List;


public class Broadcast {

    /**
     * This class is an ADT for a TV broadcast (transmission)
     * Mutable, otherLanguages and schedule are unbounded (lists)
     * Builder design pattern is used with inner static class
     * This class offers methods to add and remove elements from the schedule
     */

    private String title;
    private Genre genre; // not mandatory
    private BroadcastInfo info; // not mandatory
    private BroadcastLanguage defaultLanguage;
    private List<BroadcastLanguage> otherLanguages; // not mandatory
    private List<LocalDateTime> schedule;

    private Broadcast(BroadcastBuilder builder) {

        this.title = builder.title;
        this.genre = builder.genre;
        this.info = builder.info;
        this.defaultLanguage = builder.defaultLanguage;
        this.otherLanguages = builder.otherLanguages;
        this.schedule = builder.schedule;
    }

    /**
     * MODIFY given a local date time for the broadcast
     * the new transmission is placed keeping the schedule ordered by time
     * REQUIRE schedule is already ordered
     * @param timeOfBroadcastToAdd is the local date time for the new transimssion
     */
    public void addToSchedule(LocalDateTime timeOfBroadcastToAdd) {

        Iterator<LocalDateTime> i = this.schedule.iterator();

        int c = 0;

        while(i.hasNext()) {

            if(i.next().isAfter(timeOfBroadcastToAdd)) {

                c++;

            }

        }

        this.schedule.add(c, timeOfBroadcastToAdd);

    }

    /**
     * MODIFY given a local date time for the broadcast (to identify it)
     * the transmission is removed from the schedule
     * TRUSTING List.remove
     * REQUIRE no multiple occurencies of broadcastToRemove
     * @param timeOfBroadcastToRemove is the local date time of the transmission to remove
     */
    public void removefromSchedule(LocalDateTime timeOfBroadcastToRemove) {

        Iterator<LocalDateTime> i = this.schedule.iterator();

        while(i.hasNext()) {

            this.schedule.remove(timeOfBroadcastToRemove);

        }
    }

    public static class BroadcastBuilder {

        /**
         * Builder deisgn pattern
         */
        private String title;
        private Genre genre; // not mandatory
        private BroadcastInfo info; // not mandatory
        private BroadcastLanguage defaultLanguage;
        private List<BroadcastLanguage> otherLanguages; // not mandatory
        private List<LocalDateTime> schedule;

        /**
         * ctor with madatory fields for the object
         * @param title
         * @param defaLanguage
         * @param schedule
         */
        public BroadcastBuilder(String title, BroadcastLanguage defaLanguage, List<LocalDateTime> schedule) {
            
            this.title = title;
            this.defaultLanguage = defaLanguage;
            this.schedule = schedule;
        }

        /**
         * MODIFY add genre field to the BroadcastBuilder
         * @param genre
         * @return builder
         */
        public BroadcastBuilder withGenre(Genre genre) {

            this.genre = genre;

            return this;

        }

        /**
         * MODIFY add info field to the BroadcastBuilder
         * @param info
         * @return builder
         */
        public BroadcastBuilder withInfo(BroadcastInfo info) {

            this.info = info;

            return this;

        }

        /**
         * MODIFY add otherLanguages field to the BroadcastBuilder
         * @param otherLanguages
         * @return builder
         */
        public BroadcastBuilder withOtherLanguages(List<BroadcastLanguage> otherLanguages) {

            this.otherLanguages = otherLanguages;

            return this;

        }

        /**
         * BUILDER
         * @return the built Broadcast object
         */
        public Broadcast build(){

            return new Broadcast(this);

        }
    }
    
}

