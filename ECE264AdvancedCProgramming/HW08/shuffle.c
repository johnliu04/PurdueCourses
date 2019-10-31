// Please edit this file as required.
// You may add more functions/variables/structures in this file (if needed).

#include "shuffle.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void recursion1(CardDeck upper_deck, CardDeck lower_deck, CardDeck *final_deck, int u, int l, int f);

#ifdef TEST_DIV
void divide(CardDeck orig_deck, CardDeck * upper_deck, CardDeck * lower_deck)
{
	// Dividing the decks into the way mentioned in Readme - as lower and upper decks

	// starting from i = 0 -> size-1 copying into upper deck and lower decks
	for(int i = 0; i < orig_deck.size -1; i++){
	  
		// For example: strncpy((upper_deck[i]).cards, orig_deck.cards,i+1);
		strncpy(upper_deck[i].cards, orig_deck.cards, i + 1);
		// Update the size of the upper and lower decks after copying each element.
			// For example: upper_deck[i].size = i+1;
		upper_deck[i].size = i + 1;
		// Similarly perform the string copy, and size update operation on the lower deck.
			//For example: strncpy((lower_deck[i]).cards, orig_deck.cards+i+1,orig_deck.size-i-1);
		strncpy(lower_deck[i].cards, orig_deck.cards+i+1, orig_deck.size-i-1);
		    // For example: lower_deck[i].size = orig_deck.size -i - 1;
		lower_deck[i].size = orig_deck.size-i-1;
	}
	
	return;
}
#endif

#ifdef TEST_INTER
void interleave(CardDeck upper_deck, CardDeck lower_deck)
{
    // Follow instructions in the README, to understand the working of the recursive function.
    // Use print_deck(…) to print each resulting order.
    // Tip: There should be no uncertainty in this function.
        //If you think a random number generator is needed, you are on the wrong track.
    // Tip: To copy the elements of one array from one array to another (e.g., the array of cards in a CardDeck),
        //you could use memcpy(…).
        //The = operator will simply copy the address, not the elements themselves.
	CardDeck * final_deck = malloc((upper_deck.size + lower_deck.size)*sizeof(CardDeck));
	for (int i = 0; i < (upper_deck.size + lower_deck.size); i++){
	  final_deck -> cards[i] = 0;
	}
	final_deck -> size = (upper_deck.size + lower_deck.size);
	
	recursion1(upper_deck, lower_deck, final_deck, 0, 0, 0); // 0 is the index of each deck
	
	free(final_deck);
	return;
}

void recursion1(CardDeck upper_deck, CardDeck lower_deck, CardDeck *final_deck, int u, int l, int f)
{   
    //upper deck is empty
    if (u == upper_deck.size && l < lower_deck.size){
      for (int i = 0; i < lower_deck.size; i++){
      final_deck-> cards[f+i] = lower_deck.cards[l+i];
      }
      f = final_deck->size;
    }
    
    //lower deck is empty
    else if (l == lower_deck.size && u < upper_deck.size){
      for (int i = 0; i < upper_deck.size; i++){
      final_deck-> cards[f+i] = upper_deck.cards[u+i];
      }
      f = final_deck->size;
    }
    
    //print the deck
    if(f == final_deck->size){
      CardDeck deck;
      for (int i = 0; i < (final_deck->size); i++){
	deck.cards[i] = final_deck -> cards[i];
      }
      deck.size = final_deck -> size;
      print_deck(deck);
    
      return;
     } 
    
    //pick one from upper
      final_deck->cards[f] = upper_deck.cards[u];
      recursion1(upper_deck, lower_deck, final_deck, u + 1, l, f + 1);
      final_deck->cards[f] = lower_deck.cards[l];
      recursion1(upper_deck, lower_deck, final_deck, u, l + 1, f + 1);
     
     return;
}
#endif


#ifdef TEST_SHUF
void shuffle(CardDeck orig_deck)
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
	CardDeck * upper_deck = NULL;
	CardDeck * lower_deck = NULL;
	
	// allocate memory based on number of pairs
	   //For example: upper_deck = malloc(numpairs*sizeof(CardDeck));
	upper_deck = malloc(pairs*sizeof(CardDeck));
	lower_deck = malloc(pairs*sizeof(CardDeck));
	
	// call divideDeck to fill upper_deck and lower_deck
	divide(orig_deck, upper_deck, lower_deck);
	
	//run a loop through all the pairs
		// for each pair of upper and lower deck call interleave()
		// For example: interleave(upper_deck[i],lower_deck[i]);
	for (int i = 0; i < pairs; i++){
		interleave(upper_deck[i], lower_deck[i]);
	}

    // free memory allocated to upper and lower deck.
    free(upper_deck);
    free(lower_deck);
}
#endif
