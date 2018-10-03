package builder;

import hardware.Processor;
import hardware.Memory;
import hardware.HardDisk;

public class EmbeddedSystemBuilder implements IBuilder {

    // Embedded system processor settings
    private static final String PROCESSOR_TYPE = "RISC";
    private static final int PROCESSOR_CACHE = 3;
    private static final int PROCESSOR_CORES = 1;
    private static final double PROCESSOR_CLOCK = 1.5;
    
    
    // Embedded system memory settings
    private static final String MEMORY_TYPE = "ROM";
    private static final int MEMORY_SIZE = 2;
    private static final double MEMORY_VOLTAGE = 1.5;

    //Embedded system harddisk settings
    private static final String HARDDISK_TYPE = "SATA";
    private static final int HARDDISK_SIZE = 500;

    public EmbeddedSystemBuilder(){

    }

    @Override    
    public Processor getProcessor(){
        return new Processor(PROCESSOR_TYPE, PROCESSOR_CACHE,PROCESSOR_CORES, PROCESSOR_CLOCK);
    }
    
    @Override    
    public Memory getMemory(){
        return new Memory(MEMORY_TYPE,MEMORY_SIZE,MEMORY_VOLTAGE);
    }

    @Override
    public HardDisk getHardDisk(){
        return new HardDisk(HARDDISK_TYPE, HARDDISK_SIZE);
    }

}
