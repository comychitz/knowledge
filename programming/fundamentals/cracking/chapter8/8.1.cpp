#include <iostream>
#include <string>
#include <vector>

/**
 * Question 
 *
 * Design the data structures for a generic deck of cards. Explain how you would
 * subclass the data structures to implement blackjack.
 */

enum CardSuit {
  HEART,
  DIAMOND,
  SPADE,
  CLOVER
};

enum CardValue {
  ACE = 1,
  TWO,
  THREE,
  FOUR,
  FIVE,
  SIX,
  SEVEN,
  EIGHT,
  NINE,
  TEN,
  JACK,
  QUEEN,
  KING
};

class Card
{
  public:
    Card() { }

    virtual ~Card() { }

    virtual int value() const
    {
      return val_;
    }

    Suit suit() const
    {
      return suit_;
    }

  protected:
    CardSuit suit_;
    CardValue val_;
};

class BlackJackCard : public Card
{
  public:
    BlackJackCard() { }

    virtual ~BlackJackCard() { }

    int value() const
    {
      if(val_ < 10)
      {
        return val_;
      }
      return 10;
    }
};

class Hand
{
  public:
    virtual ~Hand() { }

    /**
     * add a card to the hand
     */
    virtual void add(Card card) = 0;

    /**
     * remove a card from the hand
     */
    virtual void remove(const Card &card) = 0;
};

class Deck
{
  public:
    Deck();

    ~Deck();

    /**
     * get the top most card
     */
    Card top();

    /**
     * add card to the bottom of the deck
     */
    void add(Card card);

    /**
     * shuffle the deck of cards
     */
    void shuffle();

    /**
     * check if the deck is empty
     */ 
    bool empty() const;

  private:
    std::queue<Card*> cards_;
};


int main(int argc, const char *argv[])
{

  
  return 0;
}
