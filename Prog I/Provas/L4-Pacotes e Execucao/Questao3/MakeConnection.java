class MakeConnection{
    public int i;

    public boolean  MakeConnection(int i){
        if (i == 0){
            ChecksumException();
            System.out.println("ChecksumException");
            return i = i* 2;
        }
        if( i == 1){
            LostSignalException();
            System.out.println("LostSignalException");
            return i = i * 2;
        }
        if(i == 2){
            EthernetException();
            System.out.println("EthernetException");
            return i = i * 2;
        }
        if(i == 3){
            WirelessException();
            System.out.println("WirelessException");
            return i = i * 2;
        }
        if(i == 4){
            NetworkException();
            System.out.println("NetworkException");
            return i = i * 2;
        }
    }
}
