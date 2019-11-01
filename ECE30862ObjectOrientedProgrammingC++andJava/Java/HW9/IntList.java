public class IntList implements MyList{
    int data;
    IntList next;

    public IntList(IntList n, int d){
        data = d;
        next = n;
    }

    public int getData( ){
        return data;
    }

    public IntList next( ){
        return next;
    }

    public void printNode( ){
        System.out.println("IntList Node, data is: "+data);
    }
}