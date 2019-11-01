public class Main {

   public static boolean foo( ) {return false;}

   public static void main(String[] args) {
      Base b = new Base( );
      Derived d = new Derived( );
      if (foo( )) {
         b = d; 
      } 
      d = (Derived) b;
   }
}
