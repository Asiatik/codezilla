package hardware;


public class Processor {

    private String processorType;
    private int cache;
    private int cores;
    private double clock;

    public Processor( String processorType, int cache, int cores, double clock ) {
        this.processorType = processorType;
        this.cache = cache;
        this.cores = cores;
        this.clock = clock;
    }

    public String getType(){
        return this.processorType;
    }

    public int getCache(){
        return this.cache;
    }

    public int getCores(){
        return this.cores;
    }

    public double getClock(){
        return this.clock;
    }

    public String toString(){
        String retString = "== Processor == \n";
        retString += "Processor type: " + this.processorType + "\n";
        retString += "Processor cache: " + String.valueOf(this.cache) + "\n";
        retString += "Processor cores: " + String.valueOf(this.cores) + "\n";
        retString += "Processor clock: " + String.valueOf(this.clock) + "\n";
        return retString;
    }

}
