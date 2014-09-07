#ifndef GSM_H
#define GSM_H


#include <QMainWindow>
#include <QVector>  //vectores donde guardar los registros
#include "QDebug"

namespace Ui {
class GSM;
}

class GSM : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit GSM(QWidget *parent = 0);
    void llenaRegistros();  //usamos los bit de la semilla para llenar los vectores que hacen la funcion de registro
    void secuenciaCifrante();  //para que nos de un bit de datos cifrantes para luego hacer xor con el texto y cifrar
    void funcionMayoria();  //que registro actualiza??
    void tobinario (int value);
    void actualizarRegistros();  //usando funcionmayoria actualizamos los vectores
    void moverRegistro(int reg);  //lo usa actualizarRegistros para añadir los bit de entrada a los registros que se mueven
    void bytetoQstring();    
    ~GSM();
    
private slots:
    void on_salir_clicked();

    void on_ejecutar_clicked();

private:
    Ui::GSM *ui;
    QVector<int> registro1,registro2,registro3;  //vectores donde guardamos la semilla en registros
    QString semilla,texto,cifrado,byte,secuenciaUtilizada,textoTobinario,byteCifra;
    int byteCifrante[8];  //guardamos byte para hacer xor con texto a cifrar    
    int mayoria;  //resultado de la funcion mayoria
    int salida,valor;  //guarda xor entre texto y bytecifrante
    char numBinario[8];

};

#endif // GSM_H
