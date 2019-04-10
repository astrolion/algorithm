#include "bits/stdc++.h"
using namespace std;

struct kmp {
        string text;
        string pattern;
        vector< int > lps;
        vector< int > positions;

        kmp( string text, string pattern ) : text(text),
                pattern(pattern) {
                LPS();

                int i = 0, j = 0;

                while( i < text.size() ) {
                        if( text[i] == pattern[j] ) {
                                i++, j++;
                        }

                        if( j == (int)pattern.size() ) {
                                positions.push_back( i - j );
                                j = lps[j - 1];
                        } else if( i < text.size() && text[i] ^ pattern[j] ) {
                                if( j != 0 ) {
                                        j = lps[j - 1];
                                } else i++;
                        }
                }
        }

        void LPS() {
                lps.resize( pattern.size() );
                lps[0] = 0;
                int cur = 1;
                int len = 0;

                while( cur < pattern.size() ) {
                        if( pattern[cur] == pattern[len] ) {
                                lps[cur++] = ++len;
                        } else {
                                if( len == 0 )
                                        lps[cur++] = 0;
                                else
                                        len = lps[len - 1];
                        }
                }
        }

        vector< int > get_positions() {
                return positions;
        }


        int total_positions() {
                return (int) positions.size();
        }


        void view_LPS() {
                for(auto x : lps) {
                        cout << x << " ";
                }
                cout << endl;
        }



};

int main() {

        string text, pattern;
        cin >> text >> pattern;

        kmp kp(text, pattern);

        for(auto x: kp.get_positions() ){
                cout<<x<<" ";
        }
        cout<<endl;


        return 0;
}
