// Pegasus Frontend
// Copyright (C) 2017  Mátyás Mustoha
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <http://www.gnu.org/licenses/>.


#include <QtTest/QtTest>

#include "ConfigFile.h"


class test_ConfigFile : public QObject {
    Q_OBJECT

private slots:
    void empty();
    void datablob();
};

void test_ConfigFile::empty()
{
    QByteArray buffer;
    QTextStream stream(buffer);

    config::Config config = config::readStream(stream);

    QCOMPARE(config.isEmpty(), true);
}

void test_ConfigFile::datablob()
{
    QByteArray buffer(1024, 0x0);
    QTextStream stream(buffer);

    QTest::ignoreMessage(QtWarningMsg, QRegularExpression("`.*?`: line [0-9]+ is invalid, skipped"));
    config::Config config = config::readStream(stream);

    QCOMPARE(config.isEmpty(), true);
}


QTEST_MAIN(test_ConfigFile)
#include "test_ConfigFile.moc"

