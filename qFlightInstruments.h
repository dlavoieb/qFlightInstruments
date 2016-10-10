#ifndef __QFLIGHTINSTRUMENTS_H__
#define __QFLIGHTINSTRUMENTS_H__

#include <QtCore>
#include <QtGui>
#include <QWidget>
#include <QMap>
#include <QTableWidget>


typedef QMap<QString, QString> ListMap;

///
/// \brief The List view class, it will display key-value pair in lines
///
class QKeyValueListView : public QTableWidget
{
public:
    Q_OBJECT

public:
    QKeyValueListView(QWidget *parent = 0);
    virtual ~QKeyValueListView();

    ///
    /// \brief Set list data
    /// \param d - list data
    ///
    void setData(ListMap &d) {
        m_data = d;
        emit listUpdate();
    }

    ///
    /// \brief Get list data
    /// \param d - list data obj
    ///
    ListMap& getData(void) {
        return m_data;
    }

    void beginSetData(void) {
        m_mutex->lock();
    }

    void endSetData(void) {
        m_mutex->unlock();
    }

    ///
    /// \brief Reloat data to table widget
    ///
    void listReload(void) {
        emit listUpdate();
    }

signals:
    void listUpdate(void);

protected slots:
    void listUpdate_slot(void);

protected:
    ListMap         m_data;
    QMutex          *m_mutex;
};

#endif // end of __QFLIGHTINSTRUMENTS_H__
