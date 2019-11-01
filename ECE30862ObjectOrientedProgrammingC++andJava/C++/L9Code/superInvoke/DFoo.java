import java.io.*;

public class DFoo extends Foo {

   private final String dfooString;

   public DFoo(String ln) {dfooString = ln;}
   public void print( ) {
      System.out.print("DFoo, printing super: ");
      super.print( );
      System.out.println("DFoo: "+dfooString);
   }
}
