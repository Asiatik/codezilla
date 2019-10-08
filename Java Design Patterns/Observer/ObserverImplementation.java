package Observer;

/**
 *
 * @author Juan Manuel Gutierrez
 * @param <E> generic parameter used to represent a message object
 */
public class ObserverImplementation<E> implements Observer {

    //variables
    private Subject subject;
    private final E subject_obj;
    private int call_count;

    /**
     * Constructor
     * @param subject_obj 
     */
    public ObserverImplementation(E subject_obj){
        this.subject_obj = subject_obj;
        this.call_count = 0;
    }
    
    @Override
    public void update() {
        if (subject == null) {
            System.out.println("ERROR: Subject is null");
            return;
        }
        String update_message = (String) subject.getUpdate(this);
        if (update_message != null){
            call_count++;
            System.out.println("Subject: "+subject_obj.toString()+" (Call count: "+call_count+") update message: "+update_message);
        } else {
            System.out.println("Subject: "+subject_obj.toString()+" : Sorry, I don't have new messages");
        }
    }

    @Override
    public void setSubject(Subject subject) {
        this.subject = subject;
    }
    
}
