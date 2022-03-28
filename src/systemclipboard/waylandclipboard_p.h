/*
    SPDX-FileCopyrightText: 2020 David Edmundson <davidedmundson@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef WAYLANDCLIPBOARD_H
#define WAYLANDCLIPBOARD_H

#include "ksystemclipboard.h"

#include <memory>

class DataControlDevice;
class DataControlDeviceManager;
class wl_event_queue;

class WaylandClipboard : public KSystemClipboard
{
public:
    WaylandClipboard(QObject *parent = nullptr);
    ~WaylandClipboard();
    void setMimeData(QMimeData *mime, QClipboard::Mode mode) override;
    void clear(QClipboard::Mode mode) override;
    const QMimeData *mimeData(QClipboard::Mode mode) const override;

    bool isValid();

private:
    std::unique_ptr<DataControlDeviceManager> m_manager;
    std::unique_ptr<DataControlDevice> m_device;
    std::unique_ptr<wl_event_queue, void (*)(wl_event_queue *)> m_eventQueue;
    QMetaObject::Connection m_dispatchConnection;
};

#endif
