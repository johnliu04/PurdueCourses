public class Main {
   public static void main(String[] args) {
      Base b = new Base( );
      Derived d = new Derived( );
      b = d; // OK, Derived ISA Base
      // d = b; // ILLEGAL! Compile time error
                // Base ISA not a Derived
      d = (Derived) b; 
    }
}
