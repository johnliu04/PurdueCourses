The way I've written this there is a nasty cyclic dependentce.  X needs the
definition of Y, and Y needs the declaration of X.  The forward dependent 
"class X;" in Y.h is used to break this cycle.
