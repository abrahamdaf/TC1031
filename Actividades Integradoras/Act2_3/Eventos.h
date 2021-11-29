#ifndef EVENTOS_H
#define EVENTOS_H

using namespace std;

class Eventos{
private:
    double fechaFormato;
    string ip;
    string descripcion;
    string fecha;
public:
    Eventos();
    Eventos(double, string, string, string );
    ~Eventos();

    double getFechaFormato() const;
    string getFecha() const;
    string getIp() const;
    string getIpAndPort() const;
    double getIpNum() const;
    string getDescripcion() const;

    void setFechaFormato(double);
    void setFecha(string);
    void setIp(string);
    void setDescripcion(string);

    void desplegarEvento();

};

Eventos::Eventos(){
    fechaFormato = 0;
    ip = "";
    descripcion = "";
    fecha = "";
}

Eventos::~Eventos(){
}

Eventos::Eventos(double _fechaFormato, string _ip, string _descripcion, string _fecha){
    fechaFormato = _fechaFormato;
    ip = _ip;
    descripcion = _descripcion;
    fecha = _fecha;
}

double Eventos::getFechaFormato() const{
    return fechaFormato;
}

string Eventos::getFecha() const{
    return fecha;
}

string Eventos::getIp() const{
    stringstream ss (ip);
    stringstream out;
    string dat1, dat2, dat3, dat4;
    string ip;
    getline(ss, dat1, '.');
    getline(ss, dat2, '.');
    getline(ss, dat3, '.');
    getline(ss, dat4, ':');
    out << dat1 << "." << dat2 << "." << dat3 << "." << dat4;
    out >> ip;
    return ip;
}

double Eventos::getIpNum() const{
    stringstream ss (ip);
    stringstream out;
    string dat1, dat2, dat3, dat4;
    double num;
    getline(ss, dat1, '.');
    getline(ss, dat2, '.');
    getline(ss, dat3, '.');
    getline(ss, dat4, ':');
    out << dat1 << dat2 << dat3 << dat4;
    out >> num;
    return num;
}

string Eventos::getDescripcion() const{
    return descripcion;
}

void Eventos::setFechaFormato(double _fechaFormato){
    fechaFormato = _fechaFormato;
}

void Eventos::setFecha(string _fecha){
    fecha = _fecha;
}

void Eventos::setIp(string _ip){
    ip = _ip;
}

void Eventos::setDescripcion(string _descripcion){
    descripcion = _descripcion;
}

void Eventos::desplegarEvento(){
    cout << fecha << " " << ip << " " << descripcion << endl;
}

#endif 