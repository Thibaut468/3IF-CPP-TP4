/*************************************************************************
       InputLogStream  -  Gestion d'un log en flux d'entrée
                             -------------------
    début                : 14/01/2020
    copyright            : (C) 2020 par GRAVEY Thibaut & CHEN Gong
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <InputLogStream> (fichier InputLogStream.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "InputLogStream.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type InputLogStream::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

string & InputLogStream::GetServerUrl()
// Algorithme :
//
{
    return serverURL;
} //----- Fin de GetServerUrl


//------------------------------------------------- Surcharge d'opérateurs
InputLogStream & InputLogStream::operator = (const InputLogStream & uniflogstream )
// Algorithme :
// Evite l'appel au constructeur de copie. Un flux ne se copiant pas.
{
    return *this;
} //----- Fin de operator =

InputLogStream & operator >> (InputLogStream & ils, LogElement & le)
//Algorithme
{
    string tampon;

    if(ils)
    {
        //IP
        getline(ils,le.GetInfos().IP,' ');

        //userLogName
        getline(ils,le.GetInfos().userLogName,' ');

        //authentificatedUser
        getline(ils,le.GetInfos().authentificatedUser,' ');

        //date
        getline(ils,tampon,']');
        tampon.erase(0,1);
        le.GetInfos().date=tampon;

        ils.seekg(2,ios_base::cur);

        //request
        getline(ils, tampon, '"');
        le.GetInfos().request=tampon;

        ils.seekg(1,ios_base::cur);

        //statusCode
        try
        {
            getline(ils, tampon, ' ');
            le.GetInfos().statusCode=stoi(tampon);

        }
        catch (exception e)
        {
            le.GetInfos().statusCode=0;
        }

        //dataQuantity
        try
        {
            getline(ils, tampon, ' ');
            le.GetInfos().dataQuantity = stoi(tampon);
        }
        catch (exception e)
        {
            le.GetInfos().dataQuantity=0;
        }

        //referer
        getline(ils, tampon, ' ');
        tampon.erase(0,1);
        tampon.erase(tampon.length()-1);

        size_t pos = tampon.find(ils.GetServerUrl());
        if(pos!=string::npos)
        {
            tampon.erase(pos,ils.GetServerUrl().length());
        }
        le.GetInfos().referer=tampon;

        //idNaviguateur
        getline(ils, tampon, '\n');
        tampon.erase(0,1);
        tampon.erase(tampon.length()-1);
        le.GetInfos().idNavigateur=tampon;

    }
    else
    {
        cerr << "End of file. Not enough data to create an other LogElement.";
    }


    return ils;

} // ------ Fin de operator >>

//-------------------------------------------- Constructeurs - destructeur

InputLogStream::InputLogStream (const string & cheminAcces,const string & url) : ifstream(cheminAcces), serverURL(url)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <InputLogStream>" << endl;
#endif
} //----- Fin de InputLogStream


InputLogStream::~InputLogStream ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <InputLogStream>" << endl;
#endif
} //----- Fin de InputLogStreameam


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

InputLogStream::InputLogStream (const InputLogStream & uniflogstream )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <InputLogStream>" << endl;
#endif
} //----- Fin de InputLogStream (constructeur de copie)

