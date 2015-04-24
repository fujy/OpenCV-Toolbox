#include "commandlistmodel.h"
#include "command/acommand.h"

#include<QVariant>
#include<QModelIndex>
#include<QList>

CommandListModel::CommandListModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

QList<ACommand*> &CommandListModel::CommandList()
{
    return commandList;
}

int CommandListModel::rowCount(const QModelIndex &parent) const
{
    return commandList.count();
}

QVariant CommandListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() >= commandList.size())
        return QVariant();

    if (role == Qt::DisplayRole)
        return QVariant(commandList.at(index.row())->CommandName());
    else
        return QVariant();
}

QVariant CommandListModel::headerData(int section, Qt::Orientation orientation,
                                     int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal)
        return QString("Column %1").arg(section);
    else
        return QString("Row %1").arg(section);
}


