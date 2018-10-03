package hardware;



public class Memory {
    private String memoryType;
    private int size;
    private double voltage;

    public Memory(String memoryType, int size, double voltage){
        this.memoryType = memoryType;
        this.size = size;
        this.voltage = voltage;
    }

    public String getType(){
        return this.memoryType;
    }

    public int getSize(){
        return this.size;
    }

    public double getVoltage(){
        return this.voltage;
    }

    public String toString(){
        String retString = "== MEMORY == \n";
        retString += "Memory type : " + this.memoryType + "\n";
        retString += "Memory Size : " + String.valueOf( this.size ) + "\n";
        retString += "Memory voltage : " + String.valueOf( this.voltage ) + "\n";
        return retString;
    }
}
