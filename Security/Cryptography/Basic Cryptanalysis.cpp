/*
//this is the actual cipher used for this exercise. we have to find this out somehow...
//f d g r e w q v t u h o z y j m i s l c p n a k x b
//a b c d e f g h i j k l m n o p q r s t u v w x y z
The hill-climbing algorithm:
    1. Generate a random key, called the 'parent', decipher the ciphertext using this key. Rate the fitness of the deciphered text, store the result.
    2. Change the key slightly (swap two characters in the key at random), measure the fitness of the deciphered text using the new key.
    3. If the fitness is higher with the modified key, discard our old parent and store the modified key as the new parent.
    4. Go back to 2, unless no improvement in fitness occurred in the last 1000 iterations
*/
#include <fstream>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <ctime>        // std::time
using namespace std;

//Rate the fitness of the deciphered text with the given parent-key and return the result.
float fitnessRate(vector<string>& dict, vector<string>& ciphertext, string& key){
    
    
    return 0.0;
}

void monoalphabeticSubstitutionCipher(vector<string>& dict, vector<string>& ciphertext){
    map<char, char> deCipherMap;
    vector<string> deciphered;
    string parent = "fdgrewqvtuhozyjmislcpnakxb";
    int alpha;
    float fitness = 0.0f;
    std::srand (unsigned(std::time(0)));
    
    
    /*
     * 1. Generate a random key, called the 'parent', decipher the ciphertext using this key. 
     * Rate the fitness of the deciphered text, store the result.
     */
    random_shuffle(parent.begin(), parent.end());
    //create the map of alphabet cipher
    alpha = 97; //97 for a
    for(string::iterator ch=parent.begin(); ch!=parent.end(); ++ch){
        deCipherMap.insert(make_pair(*ch, static_cast<char>(alpha)));
        ++alpha;
    }
    /*
    //print cipher map
    for(map<char, char>::iterator ch=cipherMap.begin(); ch!=cipherMap.end(); ++ch){
        ++(ch-> second);
        cout << ch->first << " "<< ch-> second << endl;
    }
    */
    //Decipher the ciphertext using the parent key
    deciphered.reserve(ciphertext.size());
    for(vector<string>::iterator it=ciphertext.begin(); it!=ciphertext.end(); ++it){
        string ds = "", s = *it;
        //cout << *it;
        for(string::iterator ch=s.begin(); ch!=s.end(); ++ch){
            if (*ch != ' ')
                ds += deCipherMap.at(*ch);
            else
                ds += " ";
        }
        
    }
    //Rate the fitness of the deciphered text and store the result.
    fitness = fitnessRate(dict, ciphertext, parent);
    
    
    
    
    
    return;
}


int main(){
    vector<string> dict;
    string line;
    ifstream myfile ("dictionary.lst");
    vector<string> ciphertext;
    while(getline (cin,line)){
        ciphertext.push_back(line);
    }
    sort(ciphertext.begin(), ciphertext.end());
    for(auto& i : ciphertext) cout << i << " ";
    cout << endl;
    if (myfile.is_open()){
        while (getline (myfile,line)){          
            transform(line.begin(), line.end(), line.begin(), ::tolower);
            dict.push_back(line);
            cout << line << " ";
        }
        myfile.close();
    }
    else 
        cout << "Unable to open file: dictionary.lst\n";
    //monoalphabeticSubstitutionCipher(dict, ciphertext);
    return 0;
}
