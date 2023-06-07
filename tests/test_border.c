#include <LCUI.h>
#include <pandagl.h>
#include <ui_xml.h>
#include <platform/main.h>

int main(void)
{
	int ret = 0;
	ui_widget_t *root, *box;

	lcui_init();
	box = ui_load_xml_file("test_border.xml");
	if (!box) {
		lcui_destroy();
		return ret;
	}
	root = ui_root();
	ui_widget_append(root, box);
	ui_widget_unwrap(box);
	return lcui_main();
}