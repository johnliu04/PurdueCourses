import java.io.*;

class Test {

   public static void main(String args[]) {
      Foo f = new Foo("a new foo");
      f.print( );
   
      DFoo d = new DFoo("a new dfoo");
      d.print( );
   
      ((Foo) d).print( );
   
      f = d;
      f.print( );
   }
}
