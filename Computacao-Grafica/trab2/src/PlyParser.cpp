#include <PlyParser.h>
#include <QFile>
#include <QTextStream>
#include <QIODevice>
#include <QDebug>

PlyParser::~PlyParser()
{
    pontos.clear();
    faces.clear();
}

PlyParser::PlyParser(const QString& filename)
{
    int estado = 0;
    double val;
    int i = 0, j = 0;
    int id;
    int nPF;
    bool sai = false;
    QString s;
    
    QVector<int> tmp;
	QFile file(filename);
	QString word;
        QPointF p;

	file.open(QIODevice::ReadOnly);

	QTextStream stream(&file);
	QTextStream *linha;
        do{
            s = stream.readLine();
        }while(semPalavras(s));
	linha = new QTextStream(&s, QIODevice::ReadOnly);
	while(!sai)
	{
		switch(estado)
		{
		    case 0: // primeira palavra
		        *linha >> word;
                        if(word == "comment"  || word == "format" || word == "property" || word == "ply" || word == "obj_info")
		            estado = 3;
		        else if(word == "element" )
		            estado = 1;
                        else if(word == "{"){
                            estado = 2;
                        }
		        else if(word == NULL)
		            estado = 3;
		        else if (word == "end_header")
		            estado = 4;
		        else
                            qDebug() << "ERROR [1]!:#" << word << "#";
		        break;
		       
                     case 1:
		         *linha >> word;
		         if(word == "vertex")
		         {
		            *linha >> nVertices;
		         }
		         else if(word == "face")
		         {
		            *linha >> nFaces;
		         }else 
                            qDebug() << "ERROR [2]!:#" << word << "#";
		         estado = 3;
		         break;
		        
		     case 2:
		        *linha >> word;
                        if(word == "}")
		            estado = 0;
		        else if(word == NULL){
                            delete linha;
                            do{
                            s = stream.readLine();
                         }while(semPalavras(s));
                            linha = new QTextStream(&s, QIODevice::ReadOnly);
		        }
		        break;
		        
		     case 3:
		        delete linha;
                        do{
                            s = stream.readLine();
                         }while(semPalavras(s));
                        linha = new QTextStream(&s, QIODevice::ReadOnly);
		        estado = 0;
		        break;
		        
		     case 4:
		        for(i = 0; i < nVertices; i++)
		        {
	    	        delete linha;
                        do{
                            s = stream.readLine();
                         }while(semPalavras(s));
                            linha = new QTextStream(&s, QIODevice::ReadOnly);
		            *linha >> val;
                            p.setX(val);
		            *linha >> val;
                            p.setY(val);
		            pontos.push_back(p);
		        }
		        estado = 5;
		        // Sem break
		     case 5:
		        for(i = 0; i < nFaces; i++)
		        {
		            delete linha;
                            do{
                                s = stream.readLine();
                            }while(semPalavras(s));
	                linha = new QTextStream(&s, QIODevice::ReadOnly);
    		        tmp.clear();
    		        *linha >> nPF;
    		        for(j = 0; j < nPF ; j++)
    		        {
    		            *linha >> id;
    		            tmp.push_back(id);
    		        }
    		        faces.push_back(tmp);
		        }
		        delete linha;
		        sai = true;
		}
	}
	
	indice = 0;
        file.close();
}

QVector<QPointF> PlyParser::proximo()
{
    QVector<QPointF> ret;
    
    if(indice >= nFaces)
        return ret;
        

    QVector<int> ind = faces[indice];
    
    for(int i = 0; i < ind.size() ; ++i)
    {
        ret.push_back(pontos[ind[i]]);        
    }
    
    indice++;
    
    return ret;   
}

bool PlyParser::semPalavras(QString s)
{
    s.replace(QString(" "), QString(""));
    return s.isEmpty();
}

int PlyParser::getNFaces(void)
{
    return nFaces;
}
