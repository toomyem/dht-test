
#include <simba.h>

struct dht_driver_t dht;

int main()
{
    float temperature;
    float humidity;
    int fails = 0;
    int total = 0;
    int res;

    sys_start();

    dht_init(&dht, &pin_d1_dev);
    while (1) {
        res = dht_11_read(&dht, &temperature, &humidity);
        if (res < 0) {
            std_printf("err: %d\n", res);
	    fails++;
	}
	total++;
        std_printf("t:%f, h:%f (%d/%d)\n", temperature, humidity, fails, total);
	thrd_sleep(10);
    }

    return 0;
}

