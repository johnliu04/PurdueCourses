public class LongList implements MyList{
    long data;
    LongList next;

    public LongList(LongList n, long d){
        data = d;
        next = n;
    }

    public long getData( ){
        return data;
    }

    public LongList next( ){
        return next;
    }

    public void printNode( ){
        System.out.println("LongList Node, data is: "+data);
    }
}