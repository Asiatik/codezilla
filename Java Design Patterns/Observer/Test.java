package Observer;

/**
 *
 * @author Juan Manuel Gutierrez
 */
public class Test {

    /**
     * Class used to replace generic class E
     */
    public static class TestObjectMessage {
        //variables
        private String message;
        private int position;
        
        /**
         * Constructor
         * @param message
         * @param position 
         */
        public TestObjectMessage(String message, int position) {
            this.message = message;
            this.position = position;
        }

        //getters and setters
        public String getMessage() {
            return message;
        }

        public void setMessage(String message) {
            this.message = message;
        }

        public int getPosition() {
            return position;
        }

        public void setPosition(int position) {
            this.position = position;
        }

        @Override
        public String toString() {
            return "["+position+"] "+message;
        }
    }
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        //create subject
        SubjectImplementation subject = new SubjectImplementation();

        //create observers
        Observer first_observer = new ObserverImplementation<>(new TestObjectMessage("first_observer", 1));
        Observer second_observer = new ObserverImplementation<>(new TestObjectMessage("second_observer", 2));
        
        //adding observers
        subject.addObserver(first_observer);
        subject.addObserver(second_observer);
        
        //setting observer to subject
        first_observer.setSubject(subject);
        second_observer.setSubject(subject);

        //check if any update is available
        first_observer.update();
        second_observer.update();

        subject.setChange("\"Hi I'm testing Observer Pattern\"");
        
        Observer third_observer = new ObserverImplementation<>(new TestObjectMessage("third_observer",3));
        Observer fourth_observer = new ObserverImplementation<>(new TestObjectMessage("fourth_observer",4));
        
        subject.addObserver(third_observer);
        subject.removeObserver(second_observer);
        subject.addObserver(fourth_observer);
        
        third_observer.setSubject(subject);
        fourth_observer.setSubject(subject);
        
        subject.setChange("\"Trying second test\"");
        
        subject.removeObserver(fourth_observer);
        
        subject.setChange("\"Final test\"");
        
    }
 
}
