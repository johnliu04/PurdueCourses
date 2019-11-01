import java.io.*;

public class Foo {

   private final String fooString;

   public Foo( ) {
      System.out.println("zero arg Foo constructor called"); 
      fooString = null;
   }
   public Foo(String ln) {fooString = ln;}
   public void print( ) {
      System.out.println("Foo: "+fooString);
   }
}
