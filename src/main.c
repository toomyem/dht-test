
#include <simba.h>

struct dht_driver_t dht;

int main()
{
    float temperature;
    float humidity;
    int fails = 0;
    int total = 0;
    int res;
    int n;

    sys_start();

    dht_module_init();
    dht_init(&dht, &pin_d1_dev);

    while (1) {
	n = 0;
        while (1) {
            res = dht_read_11(&dht, &temperature, &humidity);
            if (n > 15 || res == 0) {
                break;
	    }
	    n++;
            std_printf(".");
            thrd_sleep_ms(200);
	}
	total++;
        if (res < 0) {
            std_printf("err: %d\n", res);
	    fails++;
	} else {
            std_printf("t:%f, h:%f (%d/%d) n:%d\n", temperature, humidity, fails, total, n);
	}
	thrd_sleep(10);
    }

    return 0;
}

