import QtQuick 2.12
import QtQuick.Window 2.12

import "View/Common"
import "View/Common"
import "View/Menu"
import "View/Employee"

Window {
    visible: true
    width: 1920
    height: 1080
    title: qsTr("Hello World")

    LeftMenu {
        id: left
        anchors.fill: parent
    }

    CButton {
        x: 100
        y: 100
        width: 100
        height: 100
        buttonText: "Jehee"
        textSize: 32
    }


//    Loader {
//        id: loader
//        source: "./Employee/EmployeeList.qml"
//    }
}
