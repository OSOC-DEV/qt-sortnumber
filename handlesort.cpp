#include "handlesort.h"

HandleSort::HandleSort(QObject *parent):
    QObject(parent)
{
}

void HandleSort::handleSubmitTextField(const QString &in)
{
    qDebug() << "c++: HandleSort::handleSubmitTextField:" << in;
    std::stringstream ss(in.toStdString());
    std::istream_iterator<std::string> begin(ss);
    std::istream_iterator<std::string> end;
    std::vector<std::string> vstrings(begin, end);
    std::vector<int> vints;
    std::string sorted;
    QVariant QSorted;
    bool swap = true;
    try {
        std::for_each(vstrings.begin(), vstrings.end(), [&](std::string& c)
        {
            vints.push_back(std::stoi(c));
        });
        while(swap){
            swap = false;
            for (size_t i=0; i < vints.size()-1; i++){
                if (vints[i] > vints[i+1]){
                    swap = true;
                    std::swap(vints[i], vints[i+1]);
                }
            }
        }
        std::for_each(vints.begin(), vints.end(), [&](int& c)
        {
            sorted += std::to_string(c) + " ";
        });

        emit setTextField(QString::fromStdString(sorted));
    } catch (...) {
        std::cout << "Not an integer" << std::endl;
    }

}
