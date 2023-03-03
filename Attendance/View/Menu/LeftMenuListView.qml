import QtQuick 2.0

Item {
    width: parent.width
    height: parent.height

    Component.onCompleted: {
        menuInit()
    }

    ListView {
        id: menuListView
        model: menuListModel
        delegate: menuListDelegate
        highlight: Rectangle { color: "lightsteelblue"; radius: 5 }
        anchors.fill: parent
    }

    ListModel {
        id: menuListModel

    }

    Component {
        id: menuListDelegate

        Item {
            width: 300//parent.width
            height: 60

            Image {
                id: menuIcon
                x: 20
                width: 30
                height: 30
                source: "file:///D:/Attendance/Attendance/Image/icon_hamburger.png"
                anchors.verticalCenter: parent.verticalCenter
                //anchors.leftMargin: 50
            }

            Text {
                text: menuText
                font.bold: true
                font.pixelSize: 18
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: menuIcon.right
                anchors.leftMargin: 20
            }
        }
    }

    function menuInit()
    {
        //menuListModel.clear()

        menuListModel.append({menuText: "홈"})
        menuListModel.append({menuText: "직원관리"})
        menuListModel.append({menuText: "직원목록"})
        menuListModel.append({menuText: "업무현황"})
        menuListModel.append({menuText: "급여목록"})
    }
}
