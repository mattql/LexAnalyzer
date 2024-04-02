#include "parser.h"
#include "tokens.h"
#include <iostream>
using std::cout;

Parser::Parser() {
    
    tokenCount["Palavras reservadas"] = 0;
    tokenCount["Identificadores de classes"] = 0;
    tokenCount["Identificadores de propriedades"] = 0;
    tokenCount["Simbolos especiais"] = 0;
    tokenCount["Nomes de individuos"] = 0;
    tokenCount["Tipos de dados"] = 0;
    tokenCount["Cardinalidades"] = 0;
}

void Parser::Start()
{
    // enquanto não atingir o fim da entrada
    while ((lookahead = scanner.yylex()) != 0)
    {
        // trata o token recebido do analisador léxico
        switch(lookahead)
        {
            case SOME:
            case ALL:
            case VALUE:
            case MIN:
            case MAX:
            case EXACTLY:
            case THAT:
            case AND:
            case OR:
            case CLASS:
            case EQUIVALENTTO:
            case INDIVIDUALS:
            case SUBCLASSOF:
            case DISJOINTCLASSES:
                cout << "Palavra reservada: " << scanner.YYText() << "\n";
                tokenCount["Palavras reservadas"]++;
                break;

            case IDCLASSE:
                cout << "Identificador de Classe: " << scanner.YYText() << "\n";
                tokenCount["Identificadores de classes"]++;
                break;

            case IDPROP:
                cout << "Identificador de Propriedade: " << scanner.YYText() << "\n";
                tokenCount["Identificadores de propriedades"]++;
                break;

            case SYMBOL:
                cout << "Simbolo especial: " << scanner.YYText() << "\n";
                tokenCount["Simbolos especiais"]++;
                break;

            case INDIVIDNAME:
                cout << "Nomes de individuos: " << scanner.YYText() << "\n";
                tokenCount["Nomes de individuos"]++;
                break;

            case DATATYPE:
                cout << "Tipo de dado: " << scanner.YYText() << "\n";
                tokenCount["Tipos de dados"]++;
                break;

            case CARD:
                cout << "Cardinalidade: " << scanner.YYText() << "\n";
                tokenCount["Cardinalidades"]++;
                break;
        }
    }
    cout << "\n-------------------------------------" << "\n";
    
    for(const auto& e: tokenCount){
        cout << e.first << ": " << e.second << std::endl;
        cout << "-------------------------------------\n";
    }
}

