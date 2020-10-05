package Observer;

/**
 *
 * @author Juan Manuel Gutierrez
 * @param <E> generic parameter used to represent a message object
 */
public interface Observer<E> {
    
    //attach with subject to observe
    public void setSubject(Subject subject);

    //method to update the observer, used by subject
    public void update(); 
}
