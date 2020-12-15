#include <iostream>
#include <string>
using namespace std;


//the data of each player will be
//written to objects of the gamer class
class gamer
{
public:
    //game number (texas-holdem - 1 , 
    //texas-holdem - 2, five-card-draw - 3)
    int game;

    //if the player's combination is equal to
    //the next player's combination(rev = 1)
    int rav = 0;

    //cards from which the player's combination is sought
    int icard[14];

    //player cards
    int card[10] = { 0,0,0,0,0,0,0,0,0,0 };

    //player's cobmination strength (straight flush - 9,
    //four of four - 8, full house - 7, flush - 6, straight - 5,
    //set - 4, two pair - 3, one pair - 2, high card - 1)
    int power = 0;

    //those cards that are involved in the player's combination
    int pcard[10] = { -5,-5,-5,-5,-5,-5,-5,-5,-5,-5 };

};




//takes data from a string, converts it to 
//int type and writes it to an array
int* rename_texas(string s1)
{
    int chi = 0, i = 2, x = 13, s;
    s = s1.size();

    chi = (s1.size() - 23) / 5;

    int* sv = new int[chi * 4 + 12];
    sv[0] = 1;
    sv[1] = chi;
    while (x < s) {
        if (s1[x] == 'c')sv[i] = 21;
        else if (s1[x] == 'd')sv[i] = 22;
        else if (s1[x] == 'h')sv[i] = 23;
        else if (s1[x] == 's')sv[i] = 24;
        else if (s1[x] == 'A')sv[i] = 14;
        else if (s1[x] == 'K')sv[i] = 13;
        else if (s1[x] == 'Q')sv[i] = 12;
        else if (s1[x] == 'J')sv[i] = 11;
        else if (s1[x] == 'T')sv[i] = 10;
        else if (s1[x] == '9')sv[i] = 9;
        else if (s1[x] == '8')sv[i] = 8;
        else if (s1[x] == '7')sv[i] = 7;
        else if (s1[x] == '6')sv[i] = 6;
        else if (s1[x] == '5')sv[i] = 5;
        else if (s1[x] == '4')sv[i] = 4;
        else if (s1[x] == '3')sv[i] = 3;
        else if (s1[x] == '2')sv[i] = 2;
        else i--;
        i++;
        x++;
    }

    return sv;
    delete[] sv;
}


//takes data from a string, converts it to 
//int type and writes it to an array
int* rename_omaha(string s1)
{
    int chi = 0, i = 2, x = 13;

    chi = (s1.size() - 23) / 9;

    int* sv = new int[chi * 8 + 12];
    sv[0] = 2;
    sv[1] = chi;
    while (x < s1.size()) {
        if (s1[x] == 'c')sv[i] = 21;
        else if (s1[x] == 'd')sv[i] = 22;
        else if (s1[x] == 'h')sv[i] = 23;
        else if (s1[x] == 's')sv[i] = 24;
        else if (s1[x] == 'A')sv[i] = 14;
        else if (s1[x] == 'K')sv[i] = 13;
        else if (s1[x] == 'Q')sv[i] = 12;
        else if (s1[x] == 'J')sv[i] = 11;
        else if (s1[x] == 'T')sv[i] = 10;
        else if (s1[x] == '9')sv[i] = 9;
        else if (s1[x] == '8')sv[i] = 8;
        else if (s1[x] == '7')sv[i] = 7;
        else if (s1[x] == '6')sv[i] = 6;
        else if (s1[x] == '5')sv[i] = 5;
        else if (s1[x] == '4')sv[i] = 4;
        else if (s1[x] == '3')sv[i] = 3;
        else if (s1[x] == '2')sv[i] = 2;
        else i--;
        i++;
        x++;
    }

    return sv;
    delete[] sv;
}


//takes data from a string, converts it to
//int type and writes it to an array
int* rename_five(string s1)
{
    int chi = 0, i = 2, x = 15;

    chi = (s1.size() - 14) / 11;

    int* sv = new int[chi * 10 + 2];
    sv[0] = 3;
    sv[1] = chi;
    while (x < s1.size()) {
        if (s1[x] == 'c')sv[i] = 21;
        else if (s1[x] == 'd')sv[i] = 22;
        else if (s1[x] == 'h')sv[i] = 23;
        else if (s1[x] == 's')sv[i] = 24;
        else if (s1[x] == 'A')sv[i] = 14;
        else if (s1[x] == 'K')sv[i] = 13;
        else if (s1[x] == 'Q')sv[i] = 12;
        else if (s1[x] == 'J')sv[i] = 11;
        else if (s1[x] == 'T')sv[i] = 10;
        else if (s1[x] == '9')sv[i] = 9;
        else if (s1[x] == '8')sv[i] = 8;
        else if (s1[x] == '7')sv[i] = 7;
        else if (s1[x] == '6')sv[i] = 6;
        else if (s1[x] == '5')sv[i] = 5;
        else if (s1[x] == '4')sv[i] = 4;
        else if (s1[x] == '3')sv[i] = 3;
        else if (s1[x] == '2')sv[i] = 2;
        else i--;
        i++;
        x++;
    }

    return sv;
    delete[] sv;
}




//takes data from an array and writes it to class objects
gamer* texas_data_to_class(int ren[], gamer gem[])
{
    for (int k = 0, i = 12; i < ren[1] * 4 + 12; k++)       
    {
        //write down the game number
        gem[k].game = ren[0];

        for (int r = 0; r < 10; r++)
        {
            //write down the common 5 table cards
            gem[k].icard[r] = ren[r + 2];
        }

        //write down the cards in the player's hands
        gem[k].icard[10] = gem[k].card[0] = ren[i];
        gem[k].icard[11] = gem[k].card[1] = ren[i + 1];
        gem[k].icard[12] = gem[k].card[2] = ren[i + 2];
        gem[k].icard[13] = gem[k].card[3] = ren[i + 3];
        i = i + 4;
    }

    return gem;
}


//takes data from an array and writes it to class objects
gamer* omaha_data_to_class(int ren[], gamer gem[])
{
    //I write all possible combinations of cards into class objects 
    //(3 of 5 from the table and 2 of 4 from hands)
    for (int n = 0, c = 12, v = 14; v < ren[1] * 8 + 12; c = c + 8, v = v + 8)
    {
        //listing of all possible variants of the card in hand
        for (int u = c, o = v, h = 0; h < 6; h++)
        {
            //listing of all possible card options on the table
            for (int x = 2, y = 2; x < 9; x = x + 2)
            {
                for (; y < 9; y = y + 2)
                {
                    for (int i = 2, w = 4; i < 11; i = i + 2)
                    {
                        //writing down cards from the table
                        if (i != x && i != y + 2)
                        {
                            gem[n].game = ren[0];
                            gem[n].icard[w] = ren[i];
                            gem[n].icard[w + 1] = ren[i + 1];
                            w = w + 2;
                        }
                    }
                    //record cards of playing cards of playing cards of the player
                    gem[n].icard[0] = ren[u];
                    gem[n].icard[1] = ren[u + 1];
                    gem[n].icard[2] = ren[o];
                    gem[n].icard[3] = ren[o + 1];
                    //recording empty cards
                    gem[n].icard[10] = -2;
                    gem[n].icard[11] = 25;
                    gem[n].icard[12] = -3;
                    gem[n].icard[13] = 25;
                    //recording player cards
                    gem[n].card[0] = ren[c];
                    gem[n].card[1] = ren[c + 1];
                    gem[n].card[2] = ren[c + 2];
                    gem[n].card[3] = ren[c + 3];
                    gem[n].card[4] = ren[c + 4];
                    gem[n].card[5] = ren[c + 5];
                    gem[n].card[6] = ren[c + 6];
                    gem[n].card[7] = ren[c + 7];
                    n++;
                }
                y = y - (8 - x);
            }
            //changing the counter of combinations of cards in hands
            o = o + 2;
            if (o == v + 6 && u == c) {
                u = u + 2;
                o = o - 4;
            }
            else if (o == v + 6 && u == c + 2)
            {
                u = u + 2;
                o = o - 2;
            }
        }
    }

    return gem;
}


//takes data from an array and writes it to class objects
gamer* five_data_to_class(int ren[], gamer gem[])
{
    for (int k = 0, r = 2; r < ren[1] * 10 + 2; k++)
    {        
        //write down the game number
        gem[k].game = ren[0];

        for (int i = 0; i < 10; i++)
        {
            //write down the cards in the player's hands
            gem[k].icard[i] = gem[k].card[i] = ren[r + i];
        }

        r = r + 10;
        //fill in unused cells of the card
        gem[k].icard[10] = -2;
        gem[k].icard[11] = 25;
        gem[k].icard[12] = -3;
        gem[k].icard[13] = 25;
    }

    return gem;
}


//we record the best combination of each player
gamer* record_win(int chi, gamer gem[], gamer winner[])
{

    for (int i = 0; i < chi * 60; i = i + 60)
    {
        winner[i / 60] = gem[i + 59];
    }

    return winner;
}




//sort card suits alphabetically
//(in descending order in each suit)
gamer flush_sort(gamer gem)
{
    int i, k, p;

    //sort card suits alphabetically
    for(int x = 0; x < 6; x++)
    {            
        for (i = 1; i < 12; i = i + 2)
        {
            if (gem.icard[i] > gem.icard[i + 2]) {
                k = gem.icard[i];
                p = gem.icard[i - 1];

                gem.icard[i] = gem.icard[i + 2];
                gem.icard[i-1] = gem.icard[i + 1];

                gem.icard[i + 2] = k;
                gem.icard[i + 1] = p;
            }
        }
    }

    //in each suit we arrange cards
    //in descending order
    for (int x = 0; x < 6; x++)             
    {                          
        for (i = 0, k = 0; i < 11; i = i + 2)
        {
            if (gem.icard[i] < gem.icard[i + 2] && gem.icard[i + 1] == gem.icard[i + 3]) {
                k = gem.icard[i];
                gem.icard[i] = gem.icard[i + 2];
                gem.icard[i + 2] = k;
            }
        }
    }

    return gem;
}


//sort the cards in descending 
//order, ignoring the suit
int* streetsort(gamer gem) 
{
    //int m[14];
    int* m = new int[14];
    int i = 0, k;

    while (i < 14) {
        m[i] = gem.icard[i];
        i++;
    }

    for (int x = 0; x < 6; x++) 
    {                           
        for (int p, i = 0; i < 11; i = i + 2) {
            if (m[i] < m[i + 2]) {
                k = m[i];
                p = m[i + 1];

                m[i] = m[i + 2];
                m[i + 1] = m[i + 3];

                m[i + 2] = k;
                m[i + 3] = p;
            }
        }
    }

    return m;
    delete[] m;
}




//looking for a player's straight flash
gamer street_flush(gamer gem)
{
    int i, k;
    for (i = 0, k = 1; i < 11; i = i + 2)
    {

        //check if the next card is less than 1, and compare the suit
        if (gem.icard[i + 1] == gem.icard[i + 3] && gem.icard[i] - gem.icard[i + 2] == 1) {
            k++;

            //if the condition is met 4 times, write down the
            //strength of the combination and its highest card
            if (k == 5) {
                gem.power = 9;
                gem.pcard[0] = gem.icard[i - 6];
                gem.pcard[1] = gem.icard[i - 5];
                i = 11;
            }
        }
        else k = 1;

        //looking for a straight flash (5, 4, 3, 2, A)
        if (k == 4 && gem.icard[i - 4] == 5)
        {
            if ( (i > 5 && gem.icard[i - 6] == 14 && gem.icard[i - 5] == gem.icard[i - 3]) || 
                (i > 7 && gem.icard[i - 8] == 14 && gem.icard[i - 7] == gem.icard[i - 3]) || 
                (i > 9 && gem.icard[i - 10] == 14 && gem.icard[i - 9] == gem.icard[i - 3]) )
            {
                gem.power = 9;
                gem.pcard[0] = gem.icard[i - 4];
                gem.pcard[1] = gem.icard[i - 3];
                i = 11;
            }
        }
    }

    return gem;
}


//looking for a player's four of a kind
gamer square(gamer gem)
{
    int m[14], i = 0, k;

    while (i < 14) {
        m[i] = streetsort(gem)[i];
        i++;
    }

    for (i = 0, k = 1; i < 11; i = i + 2)
    {

        //check if the strength of the current
        //and the next card is equal
        if (m[i] == m[i + 2]) {
            k++;

            //if the condition is met 3 times
            //I write four of a kind and card strength
            if (k == 4 && gem.power < 8) {
                gem.power = 8;
                gem.pcard[0] = m[i - 4];
                gem.pcard[1] = m[i - 3];
                i = 0;

                //I write down the highest card not equal
                //in strength to the combination card
                while (i < 13)
                {
                    if (m[i] != gem.pcard[0]) {
                        gem.pcard[2] = m[i];
                        gem.pcard[3] = m[i + 1];
                        i = 13;
                    }
                    i = i + 2;
                }
            }
        }

        else k = 1;
    }

    return gem;
}


//looking for a player's full house
gamer full_house(gamer gem)
{
    int m[14], i = 0, k;

    while (i < 14) {
        m[i] = streetsort(gem)[i];
        i++;
    }

    for (int z = 0, x = 0, v, i = 0, k = 1; i < 11; i = i + 2)
    {
        //looking for 3 cards of the same strength
        if (m[i] == m[i + 2]) {
            k++;
            if (k == 3) {
                z = m[i];
                x = m[i + 1];
                v = 0;
                //looking for 2 cards of the same strength not equal 3
                while (v < 11)
                {
                    if (m[v] == m[v + 2] && m[v] != z && gem.power < 7) {
                        gem.power = 7;
                        //I write down the strength of 3 cards
                        gem.pcard[0] = z;
                        gem.pcard[1] = x;
                        //I write down the strength of 2 cards
                        gem.pcard[2] = m[v];
                        gem.pcard[3] = m[v + 1];
                        v = 11;
                        i = 11;
                    }
                    v = v + 2;
                }
            }
        }
        else k = 1;
    }

    return gem;
}


//looking for a player's flush
gamer flush(gamer gem)
{
    int i, k;
    for (i = 1, k = 1; i < 12; i = i + 2)
    {
        //looking for the suit of the 
        //current and the next card
        if (gem.icard[i] == gem.icard[i + 2]) {
            k++;
            
            //if the condition is met 4 times,
            //I write these cards
            if (k == 5 && gem.power < 6) {
                gem.power = 6;
                gem.pcard[0] = gem.icard[i - 7];
                gem.pcard[1] = gem.icard[i - 6];
                gem.pcard[2] = gem.icard[i - 5];
                gem.pcard[3] = gem.icard[i - 4];
                gem.pcard[4] = gem.icard[i - 3];
                gem.pcard[5] = gem.icard[i - 2];
                gem.pcard[6] = gem.icard[i - 1];
                gem.pcard[7] = gem.icard[i];
                gem.pcard[8] = gem.icard[i + 1];
                gem.pcard[9] = gem.icard[i + 2];
                i = 12;
            }
        }
        else k = 1;
    }

    return gem;
}


//looking for a player's straight
gamer street(gamer gem) {

    int m[14], i = 0, k;

    while (i < 14) {
        m[i] = streetsort(gem)[i];
        i++;
    }

    for (int z = 0, v = 0, i = 0, k = 1; i < 11; i = i + 2)
    {

        //check if the next card is less than 1
        if (m[i] - m[i + 2] == 1) {
            k++;

            //if the condition is met 4 times,
            //I write down the highest card
            if (k == 5 && gem.power < 5) {
                gem.power = 5;
                gem.pcard[0] = m[i - 6 - z * 2];
                gem.pcard[1] = m[i - 5 - z * 2];
                i = 11;
            }
        }

        //check if there are several
        //cards of the same strength in a row
        else if (m[i] == m[i + 2] && k > 1) {
            z++;
        }
        
        else k = 1;    

        //looking for a straight flash (5, 4, 3, 2, A)
          if (k == 4 && m[0] == 14 && m[i - 4 - z * 2] == 5 && gem.power < 5)
        {
            gem.power = 5;
            gem.pcard[0] = m[i - 4 - z * 2];
            gem.pcard[1] = m[i - 3 - z * 2];   
            i = 11;
        }
    }

    return gem;
}


//looking for a player's three of a kind
gamer set(gamer gem)
{
    int m[14], i = 0, k;

    while (i < 14) {
        m[i] = streetsort(gem)[i];
        i++;
    }

    for (i = 0, k = 1; i < 11; i = i + 2)
    {

        //check if the strength of the current
        //and the next card is equal
        if (m[i] == m[i + 2]) {
            k++;

            //if the condition is met 2 times
            //I write the set and the strength of the card
            if (k == 3 && gem.power < 4) {
                    gem.power = 4;
                    gem.pcard[0] = m[i];
                    gem.pcard[1] = m[i + 1]; 
                    i = 0;

                    //I write down the strongest card 
                    //not included in the street
                    while (i < 13)
                    {
                        if (m[i] != gem.pcard[0]) {
                            gem.pcard[2] = m[i];
                            gem.pcard[3] = m[i + 1];
                            i = 13;
                        }
                        i = i + 2;
                    }
                    i = 2;

                    //write down the second strongest
                    //non-straight card
                    while (i < 13)
                    {
                        if (m[i] != gem.pcard[0] && m[i] != gem.pcard[2] ) {
                            gem.pcard[4] = m[i];
                            gem.pcard[5] = m[i + 1];
                            i = 13;
                        }
                        i = i + 2;
                    }
            }
        }
        else k = 1;
    }

    return gem;
}


//looking for a player's two pairs
gamer two_pair(gamer gem)
{
    int m[14], i = 0;

    while (i < 14) {
        m[i] = streetsort(gem)[i];
        i++;
    }

    for (int z = 0, x = 0, i = 0; i < 11; i = i + 2)
    {
        //looking for the first pair
        if (m[i] == m[i + 2]) {
            z = m[i];
            x = m[i + 1];
            i = i + 2;

            //looking for a second pair
            while (i < 11)
            {

                //I write down the strength of the combination
                //and the strength of the pair cards
                if (m[i] == m[i + 2] && m[i] != z && gem.power < 3) {
                    gem.power = 3;
                    gem.pcard[0] = z;
                    gem.pcard[1] = x;
                    gem.pcard[2] = m[i];
                    gem.pcard[3] = m[i + 1];
                    i = 0;

                    //I write down the strongest card not in pairs
                    while (i < 13)
                    {
                        if (m[i] != z && m[i] != gem.pcard[2]) {
                            gem.pcard[4] = m[i];
                            gem.pcard[5] = m[i + 1];
                            i = 13;
                        }
                        i = i + 2;
                    }                 
                }
                i = i + 2;
            }
        }
    }

    return gem;
}


//looking for a player's one pair
gamer one_pair(gamer gem)
{
    int m[14], i = 0;

    while (i < 14) {
        m[i] = streetsort(gem)[i];
        i++;
    }

    //looking for 2 cards of the same strength
    for (i = 0; i < 11; i = i + 2)
    {

        //writing down the strength of the pair
        if (m[i] == m[i + 2] && gem.power < 2) {
            gem.power = 2;
            gem.pcard[0] = m[i];
            gem.pcard[1] = m[i + 1];
            i = 0;

            //looking for and writing down the
            //strongest non-pair punishment
            while (i < 13)
            {
                if (m[i] != gem.pcard[0]) {
                    gem.pcard[2] = m[i];
                    gem.pcard[3] = m[i + 1];
                    i = 13;
                }
                i = i + 2;
            }
            i = 0;

            //looking for and writing down the second 
            //strong punishment not included in the pair
            while (i < 13)
            {
                if (m[i] != gem.pcard[0] && m[i] != gem.pcard[2]) {
                    gem.pcard[4] = m[i];
                    gem.pcard[5] = m[i + 1];
                    i = 13;
                }
                i = i + 2;
            }
            i = 0;

            //looking for and writing down the third 
            //strong punishment not included in the pair
            while (i < 13)
            {
                if (m[i] != gem.pcard[0] && m[i] != gem.pcard[2] && m[i] != gem.pcard[4]) {
                    gem.pcard[6] = m[i];
                    gem.pcard[7] = m[i + 1];
                    i = 13;
                }
                i = i + 2;
            }
        }
    }

    return gem;
}


//looking for a player's high card
gamer high_card(gamer gem)
{
    int m[14], i = 0;

    while (i < 14) {
        m[i] = streetsort(gem)[i];
        i++;
    }
    if (gem.power < 1)gem.power = 1;

    //writing down the 5 strongest cards
    for (i = 0; i < 10; i++)
    {
        gem.pcard[i] = m[i];       
    }

    return gem;
}




//I check the player for 
//all possible combinations
gamer check_comb(gamer gem)
{
    //I sort the cards by suit and strength
    gem = flush_sort(gem); 

    //looking for a player's combination
    //from the strongest to the first one found
    gem = street_flush(gem);
    if (gem.power != 9)
    {
        gem = square(gem);
        if (gem.power != 8)
        {
            gem = full_house(gem);
            if (gem.power != 7)
            {
                gem = flush(gem);
                if (gem.power != 6)
                {
                    gem = street(gem);
                    if (gem.power != 5)
                    {
                        gem = set(gem);
                        if (gem.power != 4)
                        {
                            gem = two_pair(gem);
                            if (gem.power != 3)
                            {
                                gem = one_pair(gem);
                                if (gem.power != 2)
                                {
                                    gem = high_card(gem);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return gem;
}


//by the combination of each player and
//the strength of the combination cards,
//I am looking for a winner
gamer* search_win(int chi, gamer gem[])
{
    gamer g;

    for (int z = 0; z < chi - 1; z++)
    {
        for (int i = 0, chrav, k; i < chi - 1; i++)
        {

            //if the left player has a stronger
            //combination, I swap them
            if (gem[i].power > gem[i + 1].power)
            {
                g = gem[i];
                gem[i] = gem[i + 1];
                gem[i + 1] = g;
            }

            //if the combination =, then compare the cards
            if (gem[i].power == gem[i + 1].power)          
            {
                chrav = 0;
                k = 0;
                while (k < 9)
                {
                    //if the player on the right has a 
                    //stronger card, they are located 
                    //correctly, exit the cycle
                    if (gem[i].pcard[k] < gem[i + 1].pcard[k]) {
                        k = 9;
                    }

                    //if the player on the left has a 
                    //stronger card, they are not located
                    //correctly, swap the players and exit the loop
                    else if (gem[i].pcard[k] > gem[i + 1].pcard[k])
                    {
                        g = gem[i];
                        gem[i] = gem[i + 1];
                        gem[i + 1] = g;

                        k = 9;
                    }

                    //if the card =
                    else if (gem[i].pcard[k] == gem[i + 1].pcard[k])     
                    {
                        chrav++;

                        //I write down that the cards are equal
                        if (chrav == 5)
                        {
                            gem[i].rav = 1;
                        }
                    }
                    k = k + 2;
                }
            }
        }
    }

    return gem;
}


//I am looking for the best combination 
//of all possible for each player individually
gamer* omaha_search_win(int chi, gamer gem[])
{
    gamer g;
    for (int j = 0; j < chi; j++)
    {
        //we determine the winner from all possible combinations of each player individually
        for (int z = 0; z < 59; z++)
        {
            for (int i = j * 60, chrav, k; i < ((j + 1) * 60) - 1; i++)
            {
                if (gem[i].power > gem[i + 1].power)
                {
                    g = gem[i];
                    gem[i] = gem[i + 1];
                    gem[i + 1] = g;
                }

                //if the combination =, then compare the cards
                if (gem[i].power == gem[i + 1].power)
                {
                    chrav = 0;
                    k = 0;
                    while (k < 9)
                    {
                        if (gem[i].pcard[k] < gem[i + 1].pcard[k]) {
                            k = 9;
                        }
                        else if (gem[i].pcard[k] > gem[i + 1].pcard[k])
                        {
                            g = gem[i];
                            gem[i] = gem[i + 1];
                            gem[i + 1] = g;

                            k = 9;
                        }
                        k = k + 2;
                    }
                }
            }
        }
    }

    return gem;
}




//determining which comes first
//alphabetically from the two characters sent
int sr_alph(int c1, int c2)
{
    int k1 = c1, k2 = c2;

    if (k1 == 14)k1 = 10;
    else if (k1 == 13)k1 = 12;
    else if (k1 == 12)k1 = 13;
    else if (k1 == 10)k1 = 14;

    if (k2 == 14)k2 = 10;
    else if (k2 == 13)k2 = 12;
    else if (k2 == 12)k2 = 13;
    else if (k2 == 10)k2 = 14;

    if (k1 > k2)k1 = 1;
    else if (k1 == k2)k1 = 2;
    else k1 = 0;

    return k1;
}


//if the combinations of players are 
//equal, I sort them alphabetically
gamer* sort_alph(int chi, gamer gem[])
{
    int t[14];

    for (int z = 0; z < chi - 1; z++)
    {
        for (int i = 0, k; i < chi - 1; i++)
        {
            if (gem[i].rav == 1)
            {
                if ((sr_alph(gem[i].card[0], gem[i + 1].card[0]) == 1) ||
                    (sr_alph(gem[i].card[0], gem[i + 1].card[0]) == 2 && gem[i].card[1] > gem[i + 1].card[1]))
                {

                    for (k = 0; k < 10; k++)
                    {
                        t[k] = gem[i].pcard[k];
                        gem[i].pcard[k] = gem[i + 1].pcard[k];
                        gem[i + 1].pcard[k] = t[k];
                    }

                    for (k = 0; k < 10; k++)
                    {
                        t[k] = gem[i].card[k];
                        gem[i].card[k] = gem[i + 1].card[k];
                        gem[i + 1].card[k] = t[k];
                    }
                }
            }
        }
    }

    return gem;
}


//I translate the name of the cards
//from numbers to letters
char unrename(int c)
{
    char b;
    if (c == 14)b = 'A';
    else if (c == 13)b = 'K';
    else if (c == 12)b = 'Q';
    else if (c == 11)b = 'J';
    else if (c == 10)b = 'T';
    else if (c == 21)b = 'c';
    else if (c == 22)b = 'd';
    else if (c == 23)b = 'h';
    else if (c == 24)b = 's';
    else b = '0' + c;
    return b;
}


//displaying player cards
void output(int chi, gamer gem[])
{
    int i = 4;
    if (gem[0].game == 2) {
        i = 8;
    }
    else if (gem[0].game == 3) {
        i = 10;
    }

    for (int z = 0; z < chi; z++)
    {
        for (int k = 0; k < i; k++)
        {
            cout << unrename(gem[z].card[k]);
        }

        if (gem[z].rav == 1)cout << '=';
        else if (z != chi - 1)cout << ' ';
    }

    cout << '\n';

}




//game of texas_holdem
void texas_holdem(string str)
{
    //converting cards to numbers
    //and writing them to an array
    int* ren = new int[rename_texas(str)[1] * 4 + 12];
    ren = rename_texas(str);

    //transferring data from an
    //array to class objects
    gamer* gem = new gamer[ren[1]];
    gem = texas_data_to_class(ren, gem);

    //checking the combination
    //of each player
    int i = 0;
    while (i < ren[1])
    {
        gem[i] = check_comb(gem[i]);
        i++;
    }

    //determining the winner
    gem = search_win(ren[1], gem);

    //sorting of peers by alphabet
    gem = sort_alph(ren[1], gem);   

    //displaying player cards
    output(ren[1], gem);

    delete[] gem;
    delete[] ren;
}


//game of omaha_holdem
void omaha_holdem(string str)
{
    //converting cards to numbers
    //and writing them to an array
    int* ren = new int[rename_omaha(str)[1] * 8 + 12];
    ren = rename_omaha(str);

    //transferring data from an
    //array to class objects
    gamer* gem = new gamer[ren[1] * 60];
    gem = omaha_data_to_class(ren, gem);
  
    //checking the combination
    //of each player
    int i = 0;
    while (i < ren[1] * 60)
    {
        gem[i] = check_comb(gem[i]);
        i++;
    }

    //determining the best combination
    //of each player
    gem = omaha_search_win(ren[1], gem);

    //creating playersand recording in them,
    //the best combinations of the best player
    gamer* winner = new gamer[ren[1]];
    winner = record_win(ren[1], gem, winner);

    //determining the winner
    winner = search_win(ren[1], winner);

    //equal sort the results alphabetically
    winner = sort_alph(ren[1], winner);    

    //displaying player cards
    output(ren[1], winner);

    delete[] winner;
    delete[] gem;
    delete[] ren;
}


//game of five_card_draw
void five_card_draw(string str)
{
    //converting cards to numbers
    //and writing them to an array
    int* ren = new int[rename_five(str)[1] * 10 + 2];
    ren = rename_five(str);

    //transferring data from an
    //array to class objects
    gamer* gem = new gamer[ren[1]];
    gem = five_data_to_class(ren, gem);

    //checking the combination
    //of each player
    int i = 0;
    while (i < ren[1])
    {
        gem[i] = check_comb(gem[i]);
        i++;
    }

    //determining the winner
    gem = search_win(ren[1], gem);

    //sort alphabetically
    gem = sort_alph(ren[1], gem);   

    //displaying player cards
    output(ren[1], gem);

    delete[] gem;
    delete[] ren;
}





int main()
{

    string str, texas = "texas-holdem", holdem = "omaha-holdem", five = "five-card-draw";

    // read the input line by line
    //and start the Corresponding game
    while (getline(cin, str))
    {

        if (str.size() > 32 && str.find(texas) == 0) {
            texas_holdem(str);
        }

        else if (str.size() > 40 && str.find(holdem) == 0) {
            omaha_holdem(str);
        }

        else if (str.size() > 35 && str.find(five) == 0) {
            five_card_draw(str);
        }

        else cout << "Error: invalid data entry\n";  
    }

    return 1;
}