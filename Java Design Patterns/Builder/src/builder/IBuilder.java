package builder;


import hardware.Processor;
import hardware.Memory;
import hardware.HardDisk;


public interface IBuilder {

    public Processor getProcessor();
    public Memory getMemory();
    public HardDisk getHardDisk();

}
