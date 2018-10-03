package builder;

import builder.IBuilder;

import hardware.Processor;
import hardware.Memory;
import hardware.HardDisk;

public class WorkstationSystemBuilder implements IBuilder {

    // Embedded system processor settings
    private static final String PROCESSOR_TYPE = "CISC";
    private static final int PROCESSOR_CACHE = 4;
    private static final int PROCESSOR_CORES = 8;
    private static final double PROCESSOR_CLOCK = 3.5;


    // Embedded system memory settings
    private static final String MEMORY_TYPE = "DDR4";
    private static final int MEMORY_SIZE = 16;
    private static final double MEMORY_VOLTAGE = 1.5;

    //Embedded system harddisk settings
    private static final String HARDDISK_TYPE = "SSD";
    private static final int HARDDISK_SIZE = 256;
    
    
    public WorkstationSystemBuilder(){
    
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
