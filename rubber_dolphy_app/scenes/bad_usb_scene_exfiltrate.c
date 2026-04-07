#include "../helpers/ducky_script.h"
#include "../bad_usb_app_i.h"
#include "../views/bad_usb_view.h"
#include <furi_hal.h>
#include "toolbox/path.h"

#define TAG "BAD_USB_SCENE_WORK"
// TODO: improve the visuals of this scene :P

void bad_usb_scene_exfiltrate_button_callback(InputKey key, void* context)
{
        furi_assert(context);
        BadUsbApp* app = context;
        view_dispatcher_send_custom_event(app->view_dispatcher, key);
}

bool bad_usb_scene_exfiltrate_on_event(void* context, SceneManagerEvent event)
{
        UNUSED(context);
        UNUSED(event);
        bool consumed = false;

        return consumed;
}

void bad_usb_scene_exfiltrate_on_enter(void* context)
{
        BadUsbApp* app = context;
        mass_storage_init(app);
        bad_usb_view_set_button_callback(app->bad_usb_view, bad_usb_scene_exfiltrate_button_callback, app);
        widget_add_icon_element(app->exfltwdg, 0, 0, &I_EviSmile1_18x21);
        widget_add_string_multiline_element(
            app->exfltwdg,
            81,
            4,
            AlignCenter,
            AlignTop,
            FontSecondary,
            "Mounted\nMass Storage for\nExfiltration");

        view_dispatcher_switch_to_view(app->view_dispatcher, BadUsbAppViewExfiltrate);
}

void bad_usb_scene_exfiltrate_on_exit(void* context)
{
        BadUsbApp* app = context;
        mass_storage_end(app);

        view_dispatcher_switch_to_view(app->view_dispatcher, BadUsbAppViewWork);
}
