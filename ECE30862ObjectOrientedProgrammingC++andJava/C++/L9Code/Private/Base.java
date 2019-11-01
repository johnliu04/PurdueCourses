public class Base {

   public Base( ) { }
   private void print( ) {
      System.out.println("Base print");
   }

   public void callPrint(Base b) {
      b.print( );
   }
}
