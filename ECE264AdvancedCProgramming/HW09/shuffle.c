// Please modify this file as required

#include "shuffle.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void _recursion1(CardDeck upper_deck, CardDeck lower_deck, CardDeck *final_deck, int u, int l, int f, int k);
// You can add more functions, structures, and vairables to this file.  
	// Helper functions must start with '_'.

//This is an example of a helper function.
	//clean function whenever malloc fails in shuffle function
static void _error_clean()
{
	exit(EXIT_FAILURE);

}

#ifdef TEST_DIV
void divide(CardDeck orig_deck, CardDeck* upper_deck, CardDeck* lower_deck)
{
	//Dividing the desks into the way mentioned in the document - as lower and upper
	//Use a loop from index i to orig_deck.size - 1
	for (int i = 0; i < orig_deck.size -1; i++){
	  
		//starting from 1 -> size-1 copying into upper deck and lower decks
			//strncpy((upper_deck[i]).cards, orig_deck.cards,i+1);
		strncpy(upper_deck[i].cards, orig_deck.cards, i + 1);
		//update size of upper deck
			//For example: upper_deck[i].size = i+1;
		upper_deck[i].size = i + 1;
		// Similarly perform the string copy, and size update operation on the lower deck.
		strncpy(lower_deck[i].cards, orig_deck.cards+i+1, orig_deck.size-i-1);
		//update size of lower deck:
			//For example: lower_deck[i].size = orig_deck.size -i -1;
		lower_deck[i].size = orig_deck.size-i-1;
	}
	
	return; 
}
#endif


#ifdef TEST_INTER
//repeat holds the number of shuffles yet to be performed.
//after the interleave operation has been completed, you will recursively call
	//repeat_shuffle(...) with a decremented value of repeat.
void interleave(CardDeck upper_deck, CardDeck lower_deck, int repeat)
{
    // Follow instructions in the README, to understand the working of the recursive function.
    
    // when the newly shuffled deck is complete:
    	//you will perform another k-1 rounds of shuffling with the new deck
    
    // Tip: There should be no uncertainty in this function.
        //If you think a random number generator is needed, you are on the wrong track.
    // Tip: To copy the elements of one array from one array to another (e.g., the array of cards in a CardDeck),
        //you could use memcpy(…).
        //The = operator will simply copy the address, not the elements themselves.
	CardDeck * final_deck = malloc((upper_deck.size + lower_deck.size)*sizeof(CardDeck));
	if (final_deck == NULL){
	  _error_clean();
	}
	
	for (int i = 0; i < (upper_deck.size + lower_deck.size); i++){
	  final_deck -> cards[i] = 0;
	}
	//final_deck -> size = upper_deck.size + lower_deck.size;
	
	_recursion1(upper_deck, lower_deck, final_deck, 0, 0, 0, repeat); 
	// 0 is the index of each deck
	
	free(final_deck);
	return;
}

void _recursion1(CardDeck upper_deck, CardDeck lower_deck, CardDeck *final_deck, int u, int l, int f, int k)
{   
    //upper deck is empty
    if (u == upper_deck.size && l < lower_deck.size){
      for (int i = 0; i < lower_deck.size; i++){
      final_deck-> cards[f+i] = lower_deck.cards[l+i];
      }
      final_deck->size = upper_deck.size + lower_deck.size;
      repeat_shuffle(*final_deck, k -1);
      return;
    }
    
    //lower deck is empty
    else if (l == lower_deck.size && u < upper_deck.size){
      for (int i = 0; i < upper_deck.size; i++){
      final_deck-> cards[f+i] = upper_deck.cards[u+i];
      }
      final_deck->size = upper_deck.size + lower_deck.size;
      repeat_shuffle(*final_deck, k -1);
      return;
    }
    
    //print the deck
//     if(f == final_deck->size){
//       //printDeck(*final_deck);
//       //repeat_shuffle(*final_deck, k -1);
//     
//       return;
//      } 
    
    //pick one from upper
      final_deck->cards[f] = upper_deck.cards[u];
      _recursion1(upper_deck, lower_deck, final_deck, u + 1, l, f + 1, k);
    //pick one from lower
      final_deck->cards[f] = lower_deck.cards[l];
      _recursion1(upper_deck, lower_deck, final_deck, u, l + 1, f + 1, k);
  
     return;

}
#endif

#ifdef TEST_SHUF
//repeat holds the number of shuffles that are yet to be performed.
void shuffle(CardDeck orig_deck, int repeat)
{
    // declare a variable to hold the number of pairs
        // we can say that we have only size-1 possibility of pairs
	int pairs = orig_deck.size - 1;
	
    // if number of pairs == 0; return;
       if (pairs == 0){
	 return;
       }
       
	// instantiate pointers to hold both upper and lower decks (after division)
	   // For example: CardDeck * upper_deck = NULL;
	    CardDeck * upper_deck = malloc(pairs * sizeof(CardDeck));
	    if (upper_deck == NULL){
	      _error_clean();
	    }
	    
	    CardDeck * lower_deck = malloc(pairs * sizeof(CardDeck));
	    if (lower_deck == NULL){
	      _error_clean();
	    }
	    
	// allocate memory based on number of pairs
	   //For example: upper_deck = malloc(numpairs*sizeof(CardDeck));
	   
	// call divideDeck to fill upper_deck and lower_deck
	divide(orig_deck, upper_deck, lower_deck);
	
	//run a loop through all the pairs
		// for each pair of upper and lower deck call interleave()
		// For example: interleave(upper_deck[i],lower_deck[i]);
	for (int i = 0; i < pairs; i++){
	      interleave(upper_deck[i], lower_deck[i], repeat);
	}
		
    // free memory allocated to upper and lower deck.
    free(upper_deck);
    free(lower_deck);
    
    return;
    
}
#endif

#ifdef TEST_RSHUF
void repeat_shuffle(CardDeck orig_deck, int k)
{
	//orig_deck contains a deck of cards, and it's size.

	//If (k ≤ 0), no shuffling, print the only possible outcome.
	if (k <= 0){
	  //printDeck(orig_deck); and return
		//TIP: Print only the results obtained after k rounds of shuffling
	  printDeck(orig_deck);
	  return;
	}
		
	// call shuffle(orig_deck);
	shuffle(orig_deck, k);
	// TIP: In interleave(…), when the newly shuffled deck is complete, 
		//you will perform another k-1 rounds of shuffling with the new deck.
	return;
}
#endif
