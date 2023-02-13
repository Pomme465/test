#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;

string melangerLettres(string mot)
{
    string melange;
    int position(0);

    while (mot.size()!=0)
    {
        position=rand()%mot.size();

        melange+=mot[position];

        mot.erase(position, 1);
    }
    return melange;
}

int main()
{
    srand(time(NULL));

    string motMystere, motMelange, motUtilisateur;
    string ligne;
    int nombreLignes(0);
    int numLigneAleatoire;

    ifstream fichier("26_Mots_4_lettres.txt");
    if (fichier)
    {
        while (getline(fichier, ligne))
        {
            nombreLignes++;
        }


        numLigneAleatoire = rand() % nombreLignes + 1;


        fichier.clear();
        fichier.seekg(0, ios::beg);

        for (int i=0; i<numLigneAleatoire; i++)
        {
            getline(fichier, ligne);
        }

        motMystere = ligne;
        fichier.close();
    }
    else
    {
        cerr<<"Impossible d'ouvrir le fichier."<<endl;
        return 1;
    }

    motMelange = melangerLettres(motMystere);


    ofstream fichierReponses("Supreme.txt");

    do
    {
        cout<<"\nReplacez les lettres dans le bon ordre pour retrouver le mot?"<<motMelange<< "\n";
        cin>>motUtilisateur;

        fichierReponses<<motUtilisateur<<endl;

        if(motUtilisateur==motMystere)
        {
            cout<<"Bravo, vous avez reussi !"<<"\n";
        }
        else
        {
            cout<<"Ce n'est pas le mot !"<<"\n";
        }
    } while (motUtilisateur!=motMystere);

    fichierReponses.close();
    return 0;
}
