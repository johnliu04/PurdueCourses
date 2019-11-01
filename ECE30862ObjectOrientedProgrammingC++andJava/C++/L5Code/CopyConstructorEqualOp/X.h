#ifndef X_H_
#define X_H_

class X {
public:
   X(int );
   X(const X&);
   virtual ~X( );

   X& operator=(const X& xobj);

private:
   int *ages;
   int size;
};
#endif /* X_H_ */
