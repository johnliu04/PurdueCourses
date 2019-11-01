public class Test {

   public static void main(String[ ] s) {
      Base b = new Base( );
      Derived  der = new Derived( );
      b.callPrint(der);
      der.callPrint(der);
   }
}
