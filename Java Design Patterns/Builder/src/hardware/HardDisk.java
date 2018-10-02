package hardware;


public class HardDisk {

    private String type;
    private int capacity;
    
    public HardDisk(String type, int capacity ){
        this.type = type;
        this.capacity = capacity;
    }

    public String getType(){
        return this.type;
    }

    public int getCapacity(){
        return this.capacity;
    }

    public String toString(){
        String retString = "== HARDDISK == \n";
        retString += "HardDisk type : " + this.type + "\n";
        retString += "HardDisk capacity : " + this.capacity + "\n";
        return retString;
    }
}
