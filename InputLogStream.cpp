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

    try {
        //IP
        getline(ils, tampon, ' ');
        le.GetInfos().IP = tampon;

        //userLogName
        getline(ils, le.GetInfos().userLogName, ' ');

        //authentificatedUser
        getline(ils, le.GetInfos().authentificatedUser, ' ');

        //date
        getline(ils, tampon, ']');
        tampon.erase(0, 1);
        le.GetInfos().day = stoi(tampon.substr(0, 2));
        le.GetInfos().month = tampon.substr(3, 3);
        le.GetInfos().year = stoi(tampon.substr(7, 4));
        le.GetInfos().hour = stoi(tampon.substr(12, 2));
        le.GetInfos().minute = stoi(tampon.substr(15, 2));
        le.GetInfos().second = stoi(tampon.substr(18, 2));
        le.GetInfos().GMT = tampon.substr(21, 5);

        ils.seekg(2, ios_base::cur);

        //action
        getline(ils, tampon, ' ');
        le.GetInfos().action = tampon;

        //URL
        getline(ils, tampon, ' ');
        le.GetInfos().URL = tampon;

        //protocol
        getline(ils, tampon, '"');
        le.GetInfos().protocol = tampon;

        ils.seekg(1, ios_base::cur);

        //statusCode
        try {
            getline(ils, tampon, ' ');
            le.GetInfos().statusCode = stoi(tampon);

        }
        catch (exception e) {
            le.GetInfos().statusCode = 0;
        }

        //dataQuantity
        try {
            getline(ils, tampon, ' ');
            le.GetInfos().dataQuantity = stoi(tampon);
        }
        catch (exception e) {
            le.GetInfos().dataQuantity = 0;
        }

        //referer
        getline(ils, tampon, ' ');
        tampon.erase(0, 1);
        tampon.erase(tampon.length() - 1);

        size_t pos = tampon.find(ils.GetServerUrl());
        if (pos != string::npos) {
            tampon.erase(pos, ils.GetServerUrl().length());
        }
        le.GetInfos().referer = tampon;

        //idNavigateur
        getline(ils, tampon);
        tampon.erase(0, 1);
        tampon.erase(tampon.length() - 1);
        le.GetInfos().idNavigateur = tampon;

    }
    catch (exception e)
    {
        //Catch EOF OR FAIL
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

