#include "gsm.h"
#include "ui_gsm.h"
#include "QtTest/QtTest"

GSM::GSM(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GSM)
{
    ui->setupUi(this);
}

GSM::~GSM()
{
    delete ui;
}

void GSM::on_salir_clicked()
{
    close();
}
QWaitCondition waitCondition;
QMutex mutex;
void GSM::on_ejecutar_clicked()
{
    registro1.clear();
    registro2.clear();
    registro3.clear();
    secuenciaUtilizada.clear();
    textoTobinario.clear();


    //entrada de datos guardados como QString
    semilla=ui->pass->toPlainText();
    texto=ui->text->toPlainText();
    cifrado=ui->res->toPlainText();


    llenaRegistros();
    secuenciaCifrante();  //realizamos proceso ocho veces para obtener el byte que usaremos para cifrar el texto

    bytetoQstring();
    cifrado.append("RESULTADO:\t");
    for(int i=0;i<texto.size();i++) //cifrar texto usando la secuencia cifrante guardada en byteCifrante
    {
        valor=texto[i].toLatin1();
        byteCifra.append(QString::number(valor,2));
        salida = byteCifra.toInt() ^ byte.toInt();  //xor texto y byte cifrante
        cifrado.append(QString::number(salida,2));
        cifrado.append(" ");
        secuenciaUtilizada.append(byte+" ");
        secuenciaCifrante();  //actualizamos el byte cifrante
        bytetoQstring();
    }

    if(texto.isEmpty())
    {
        cifrado.append("\nSECUENCIA CIFRANTE:\t"+byte+"\n");
    }
    else
    {        
        for(int i=0;i<texto.size();i++)
        {
            valor=texto[i].toLatin1();
            tobinario(valor);
            textoTobinario.append(numBinario);
            textoTobinario.append(" ");
        }
        cifrado.append("\nSECUENCIA CIFRANTE:\t"+secuenciaUtilizada+"\nTEXTO SIN CIFRAR:\t"+textoTobinario+"\n");
    }
    ui->res->setPlainText(cifrado);
    ui->res->show();

}



void GSM::llenaRegistros()  //llenamos los registros con los bits de la semilla
{
    for(int i=0;i<64;i++) //llenamos los registros
    {
        if(i<19)
        {
            registro1.push_back(semilla[i].digitValue());
        }
        else if(i<41)
        {
            registro2.push_back(semilla[i].digitValue());
        }
        else if(i<64)
        {
            registro3.push_back(semilla[i].digitValue());
        }
    }


}

void GSM::secuenciaCifrante()  //realiza el proceso ocho veces
{
    for(int i=0;i<8;i++)
    {
        byteCifrante[i]=registro1[0]^registro2[0]^registro3[0];  //xor con los tres primeros bits
        actualizarRegistros();        
    }

}

void GSM::actualizarRegistros()
{

    funcionMayoria();
    if(mayoria==1)
    {
        if(registro1[10]==1)
            moverRegistro(1);
        if(registro2[11]==1)
            moverRegistro(2);
        if(registro3[12]==1)
            moverRegistro(3);
    }
    else if(mayoria == 0)
    {
        if(registro1[10]==0)
            moverRegistro(1);
        if(registro2[11]==0)
            moverRegistro(2);
        if(registro3[12]==0)
            moverRegistro(3);
    }   
}


void GSM::funcionMayoria()  //funcion mayoria
{
    mayoria=(registro1[10]*registro2[11])^(registro1[10]*registro3[12])^(registro2[11]*registro3[12]);    
}

void GSM::tobinario (int value){   //para crear numero binario
  for (int i = 0; i < 8; i++){
    numBinario[i] = 0;
  }
  for (int i = 7; i >= 0; --i, value >>= 1){
    numBinario[i] = (value & 1) + '0';
  }
}

void GSM::moverRegistro(int reg)
{
    int bit;
    if(reg == 1)  //movemos registro uno
    {
        bit = registro1[0]^registro1[1]^registro1[2]^registro1[5];        
        registro1.push_back(bit); //metemos el bit en el registro al final secuencia
        registro1.pop_front();//eliminamos primer bit del registro
    }
    if(reg == 2)  //movemos registro dos
    {
        bit = registro2[0]^registro2[1];        
        registro2.push_back(bit); //metemos el bit en el registro al final secuencia
        registro2.pop_front();//eliminamos primer bit del registro
    }
    if(reg == 3)  //movemos registro tres
    {
        bit = registro3[0]^registro3[1]^registro3[2]^registro3[15];
        registro3.push_back(bit); //metemos el bit en el registro al final secuencia
        registro3.pop_front();//eliminamos primer bit del registro
    }
}

void GSM::bytetoQstring()
{
    byte.clear();
    for(int i=0;i<8;i++)
    {
        byte.append(QString::number(byteCifrante[i]));  //guardamos el byte en QString        
    }    
}



