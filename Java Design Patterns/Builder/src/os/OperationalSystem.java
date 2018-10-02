package os;

import hardware.Processor;
import hardware.Memory;
import hardware.HardDisk;

public class OperationalSystem {

    private Processor proc;
    private Memory mem;
    private HardDisk hd;

    public OperationalSystem(Processor proc, Memory mem, HardDisk hd){
        this.proc = proc;
        this.mem = mem;
        this.hd = hd;
    }

    public String getHardwareInfos() {
        String returnString = "=== HARDWARE INFOS ===\n";
        returnString += this.proc.toString() + "\n";
        returnString += this.mem.toString() + "\n";
        returnString += this.hd.toString() + "\n";
        return returnString;
    }
    
}
