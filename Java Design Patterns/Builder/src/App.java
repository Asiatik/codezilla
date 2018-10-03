
import builder.Director;
import builder.IBuilder;
import builder.EmbeddedSystemBuilder;
import builder.WorkstationSystemBuilder;

import os.OperationalSystem;

public class App {

    public static void main(String[] args) {
        Director dir = new Director();
        dir.setBuilder( new EmbeddedSystemBuilder() );
        
        OperationalSystem os = dir.getOS();       
        System.out.println( os.getHardwareInfos() );  
        
        dir.setBuilder( new WorkstationSystemBuilder() );
        
        os = dir.getOS();
        System.out.println( os.getHardwareInfos() );
    }
}
