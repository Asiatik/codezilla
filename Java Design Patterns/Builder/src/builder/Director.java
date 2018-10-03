package builder;


import builder.IBuilder;
import os.OperationalSystem;

public class Director {
    private IBuilder builder;
    
    public Director(){
    
    }
    
    public void setBuilder(IBuilder builder){
        this.builder = builder;
    }

    public OperationalSystem getOS(){
        return new OperationalSystem(this.builder.getProcessor(),this.builder.getMemory(), this.builder.getHardDisk());
    }
}
