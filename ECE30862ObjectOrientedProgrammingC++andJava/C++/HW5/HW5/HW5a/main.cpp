#include "Base.h"
#include "PrivDerived.h"
#include "ProtDerived.h"
#include "PublicDerived.h"
#include "dPriv.h"
#include "dProt.h"
#include "dPublic.h"
#include <iostream>
#include <string>
using namespace std;

int main(void) {

   Base* b = new Base( );
   PrivDerived* privd = new PrivDerived( );
   ProtDerived* protd = new ProtDerived( );
   PublicDerived* publicd = new PublicDerived( );
   dPriv* dpriv = new dPriv( );
   dProt* dprot = new dProt( );
   dPublic* dpublic = new dPublic( );

   cout << "b" << endl;
   cout << b->getprivB() << endl;
   cout << b->getprotB() << endl;
   cout << b->publicB << endl;

   cout << "privd" << endl;
   cout << privd->getprivB() << endl;
   cout << privd->getprotB() << endl;
   cout << privd->getpublicB() << endl;

   cout << "protd" << endl;
   cout << protd->getprivB() << endl;
   cout << protd->getprotB() << endl;
   cout << protd->getpublicB() << endl;

   cout << "publicd" << endl;
   cout << publicd->getprivB() << endl;
   cout << publicd->getprotB() << endl;
   cout << publicd->publicB << endl;

   cout << "dpriv" << endl;
   cout << dpriv->getprivB() << endl;
   cout << dpriv->getprotB() << endl;
   cout << dpriv->getpublicB() << endl;

   cout << "dprot" << endl;
   cout << dprot->getprivB() << endl;
   cout << dprot->getprotB() << endl;
   cout << dprot->getpublicB() << endl;

   cout << "dpublic" << endl;
   cout << dpublic->getprivB() << endl;
   cout << dpublic->getprotB() << endl;
   cout << dpublic->publicB << endl;
}
