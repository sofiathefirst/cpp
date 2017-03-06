#include "utilities.h"

namespace zymns
{
    int mod( int m, int n )
    {
        if( n != 0 )
        {
            int r = m % n;
            if( r < 0 )
                r += n;

            return r;
        }
        else
        {
            cerr << "The dividend shouldn't be zero." << endl;
            return 0;
        }
    }


    /**
    * Rounds the elements of a/b to the nearest integers
    * greater than or equal to a/b.
    * e.g. ceil(10,2) = 5, ceil(10,3)=4.
    */
    int ceil( int m, int n )
    {
        if( n != 0 )
        {
            int q = m / n;
            if( m%n != 0 )
                q += 1;

            return q;
        }
        else
        {
            cerr << "The dividend shouldn't be zero." << endl;
            return 0;
        }
    }


}
