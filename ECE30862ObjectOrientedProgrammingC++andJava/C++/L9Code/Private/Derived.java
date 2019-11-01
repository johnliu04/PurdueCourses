public class Derived extends Base {

   public Derived( ) { }
   public void print( ) {
      // super.print( ); // invokes print in base 
      System.out.print("Derived Print");
   }
}
