// SPDX-License-Identifier: GPL-2.0-or-later
/** \file
 *
 * Laser Engraving Actions
 *
 * Authors:
 *   User
 *
 * Copyright (C) 2025 Authors
 *
 * Released under GNU GPL v2+, read the file 'COPYING' for more information.
 */

#include "actions-laser.h"

#include <glibmm/i18n.h>
#include <giomm.h>

#include "inkscape-application.h"
#include "actions/actions-extra-data.h"

void launch_laser_engraving()
{
    try {
        Glib::ustring uri = "file:///C:/inkscape/LaserGRBL/LaserGRBL.exe";
        Gio::AppInfo::launch_default_for_uri(uri);
    } catch (const Glib::Error& error) {
        g_warning("Failed to launch: %s", error.what());
    }
}

const Glib::ustring SECTION = NC_("Action Section", "Laser");

std::vector<std::vector<Glib::ustring>> raw_data_laser =
{
    { "app.launch-laser", N_("打开激光软件"), SECTION, N_("启动激光雕刻软件") }
};

void
add_actions_laser(InkscapeApplication* app)
{
    if (!app->gtk_app()) {
        return;
    }

    auto *gapp = app->gio_app();

    gapp->add_action("launch-laser", &launch_laser_engraving);

    app->get_action_extra_data().add_data(raw_data_laser);
}
