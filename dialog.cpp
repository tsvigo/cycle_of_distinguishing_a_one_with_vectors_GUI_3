// cycle_of_distinguishing_a_one_with_vectors_GUI_3
#include "dialog.h"
#include "ui_dialog.h"
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Dialog::Dialog
/// \param parent
#include <QTextStream>
#include <QFile>
#include <fstream>

#include <iostream>
using namespace std;
#include <QFileDialog>
#include <vector>
#include <algorithm>
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
QString    Nazvaniye_fayla_s_neyronami_i_signalom="";
long long variable_error;
int var ;
int variable_synapse_index_counter=0;
bool ostanovity_podstroyku=false;
int velichina_uvelicheniya_sinapsa=1;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void fixZeros(std::vector<long long>& list_of_synapses) {
    for (long long& synapse : list_of_synapses) {
        if (synapse == 0) {
            synapse = 1;
        }
    }
}
//########################################################################################################
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);









}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pushButton_clicked() // старт
{
velichina_uvelicheniya_sinapsa=ui->spinBox->value() ;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
          // выведем название программы
           std::cout << "  cycle_of_distinguishing_a_one_with_vectors_GUI_3" << std::endl;
        
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
// выбираем файл 
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
QString filePath = QFileDialog::getOpenFileName(this, tr("Выберите файл txt"),
 //QDir::homePath()
 "/home/viktor/my_projects_qt_2/Sgenerirovannye_fayly/Edinitsy_iz_shriftov_posle_pereustanovki_Debiana/"
 , tr("Все файлы txt (*.txt)"));
if (!filePath.isEmpty()) {
    // filePath содержит полный путь выбранного файла
    Nazvaniye_fayla_s_neyronami_i_signalom=filePath;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /// Читает нейроны и сигнал из файла в вектор.
    std::ifstream is(
          Nazvaniye_fayla_s_neyronami_i_signalom.toUtf8().constData()
        );
    std::istream_iterator<long long> start(is), end;
    std::vector<long long> list_of_neurons(start, end);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////   /// читает синапсы из файла в вектор
    std::ifstream is2(
     "/home/viktor/my_projects_qt_2/Funktsiya_Resheniya_2/synapses.txt"
    );
    std::istream_iterator<long long> start2(is2), end2;
    std::vector<long long> list_of_synapses(start2, end2);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// считаем ошибку
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
    if 
        (list_of_neurons[200]<0 ) 
    {ui->label->setText("Программа считает что это 1.");   goto d;} 
    else {        ui->label->setText("Программа считает что это не 1.");    } 

  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 b: // тут скажем проверка на переменную остановки
 QCoreApplication::processEvents();
 if (ostanovity_podstroyku==true) {goto d;}
////////////////////////////////////////////// Solution function ////////////////////////////////////////////////////////////
    for ( var = 100; var < 200; ++var) // This is the range of neurons
    {
        for (int neuron_index = 0, synapse_index = 0;   neuron_index < 200, synapse_index < 10100;   ++neuron_index, synapse_index = synapse_index + 100)
        
        {
            
            list_of_neurons[var]=list_of_neurons[var]+  (list_of_neurons[neuron_index]/ list_of_synapses[synapse_index]);    
        } // складываем нейроны
    }
// вычисляем последний решающий нейрон:
    for (int   neuron_index = 100, synapse_index = 10000; neuron_index < 200;   ++neuron_index, ++synapse_index)
    {
        list_of_neurons[200] = list_of_neurons[200] + (list_of_neurons[neuron_index] / list_of_synapses[synapse_index]);
    }
// считаем ошибку:

          std::cout << "list_of_neurons[200] = " << list_of_neurons[200]<< std::endl;
//
    if (variable_error<0) // to the exit
        goto c;
//
    if (list_of_synapses[10100]==-9223372036854775807) // to the exit
    {
        std::cout << "The values of all synapses are minimal and equal to -9223372036854775807." << std::endl;
        goto d;
    }
    // 115 строка     
 e:
    if (list_of_synapses[variable_synapse_index_counter] <9223372036854775806)
        list_of_synapses[variable_synapse_index_counter]  =  list_of_synapses[variable_synapse_index_counter]+
      velichina_uvelicheniya_sinapsa;//  1;
    //     
    // 
    if (list_of_synapses[variable_synapse_index_counter] ==9223372036854775806)
    {
        variable_synapse_index_counter = variable_synapse_index_counter+1;
        goto e;
    }
    //
    if (variable_synapse_index_counter<10100)
        variable_synapse_index_counter=variable_synapse_index_counter+1;
        // тут где-то установить скорость подстройки
        // c начала вычитаем по 1 int variable_synapse_index_counter=0;
    else
        variable_synapse_index_counter=0;
        
         goto b;
//########################################################################################################
 c:
     std::cout << "The error has disappeared. list_of_neurons[200] = " << list_of_neurons[200]<< std::endl;
   

d:
 // записываем синапсы:
 fixZeros(list_of_synapses);
//########################################################################################################
     fstream file2;
    file2.open("/home/viktor/my_projects_qt_2/Funktsiya_Resheniya_2/synapses.txt",ios_base::out);
    
    vector<long long>::iterator itr;
    
    for(itr=list_of_synapses.begin();itr!=list_of_synapses.end();itr++)
    {
        file2<<*itr<<endl;
    }
    
    file2.close();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
    if 
        (list_of_neurons[200]<0 ) 
    {ui->label->setText("Программа считает что это 1.");  } 
    else {        ui->label->setText("Программа считает что это не 1.");    } 
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  
}


void Dialog::on_pushButton_2_clicked() // стоп
{
   ostanovity_podstroyku=true; 
}

